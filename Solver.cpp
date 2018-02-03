#include "Solver.h"

Solver::Solver(const string &fileName, bool graphicalSolve)
        :graphicalSolve(graphicalSolve)
{
    Reader generator = Reader(fileName);
    if(!generator.isException())
    {
        map = generator.getMap();
        currentPosition = map.getStartPoint();
    }
    else
    {
        exception = true;
    }
}

const Coordinate &Solver::getCurrentPosition() const
{
    return currentPosition;
}

bool Solver::getIsSolved() const
{
    return isSolved;
}

bool Solver::pathExists(unsigned int x, unsigned int y)
{
    //prüft ob es das Feld überhaupt gibt
    if (x > map.getWidth())
    {
        return false;
    } else if (y > map.getHeight())
    {
        return false;
    }
    return map.at(x, y).isWalkable() && !map.at(x, y).isUsedPath();
}

bool Solver::isException() const
{
    return exception;
}

bool Solver::SolveProblem(Coordinate &position, string path)
{
    if(isSolved)
    {
        //verhindert, dass übrig bleibende Wege weiter verfolgt werden, wenn die Lösung ermittelt wurde
       return false;
    }
    try
    {
        unsigned int x = position.getX();
        unsigned int y = position.getY();
        //Setzt den Punkt als benutzt
        map.at(x, y).setUsedPath(true);
        if (map.getEndPoint() == position)
        {
            cout << "Das Labyrinth wurde gelöst!" << "\nDieser Weg ist möglich um durch " <<
                 "das Labyrinth zu kommen:\n" << path << "\n";
            isSolved = true;
            return true;
        }
        if(graphicalSolve)
        {
            cout << "Labyrinth\n" << map;
            cout << "\naktuelle Position: " << position;
            cout <<
                 "path at " << x << "," << y - 1 << " exists " << pathExists(x, y - 1) << "\n" <<
                 "path at " << x + 1 << "," << y << " exists " << pathExists(x + 1, y) << "\n" <<
                 "path at " << x << "," << y + 1 << " exists " << pathExists(x, y + 1) << "\n" <<
                 "path at " << x - 1 << "," << y << " exists " << pathExists(x - 1, y) << "\n";
            system("clear");
            system("sleep 0.6");
        }
        //Positionen werden auf Begehbarkeit abhängig von der Position geprüft
        return (pathExists(x, y - 1) && SolveProblem(map.at(x, y - 1), path+"O")) || //Norden
               (pathExists(x + 1, y) && SolveProblem(map.at(x + 1, y), path+"R")) || //Osten
               (pathExists(x, y + 1) && SolveProblem(map.at(x, y + 1), path+"U")) || //Süden
               (pathExists(x - 1, y) && SolveProblem(map.at(x - 1, y), path+"L"));   //westen
    }
    catch (const runtime_error& e)
    {
        cerr << e.what();
    }
    return false;
}
