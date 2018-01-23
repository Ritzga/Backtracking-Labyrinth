#include "Solver.h"

Solver::Solver(const string &fileName, bool fastSolve)
        : fastSolve(fastSolve) {
    Reader generator = Reader(fileName);
    map = generator.getMap();
    currentPosition = map.getStartPoint();
}

void Solver::setCurrentPosition(const Coordinate &currentPosition) {
    Solver::currentPosition = currentPosition;
}

bool Solver::pathExists(unsigned int x, unsigned int y) {
    //prüft ob es das Feld überhaupt gibt
    if (x < 0 || x > map.getWidth()) {
        return false;
    } else if (y < 0 || y > map.getHeight()) {
        return false;
    }
    return map.at(x, y).isWalkable() && !map.at(x, y).isUsedPath();
}

bool Solver::SolveProblem(Coordinate &position, string path) {
    if(isSolved)
    {
       return false;
    }
    try {
        system("clear");
        if(!fastSolve)
        {
            system("sleep 0.06");
        }
        //Positionen werden auf Begehbarkeit abhängig von der Position geprüft
        cout << "\naktuelle Position: " << position;

        //Setzt den Punkt als benutzt
        unsigned int x = position.getX();
        unsigned int y = position.getY();
        map.at(x, y).setUsedPath(true);
        cout << "Labyrinth\n" << map;

        if (map.getEndPoint() == position) {
            cout << "Das Labyrinth wurde gelöst!" << "\nDieser Weg ist möglich um durch " <<
                    "das Labyrinth zu kommen:\n" << path;
            return true;
        }
        cout <<
             "path at " << x << "," << y - 1 << " exists " << pathExists(x, y - 1) << "\n" <<
             "path at " << x + 1 << "," << y << " exists " << pathExists(x + 1, y) << "\n" <<
             "path at " << x << "," << y + 1 << " exists " << pathExists(x, y + 1) << "\n" <<
             "path at " << x - 1 << "," << y << " exists " << pathExists(x - 1, y) << "\n" <<
        endl;

        return (pathExists(x, y - 1) && SolveProblem(map.at(x, y - 1), path+"O")) || //Norden
               (pathExists(x + 1, y) && SolveProblem(map.at(x + 1, y), path+"R")) || //Osten
               (pathExists(x, y + 1) && SolveProblem(map.at(x, y + 1), path+"U")) || //Süden
               (pathExists(x - 1, y) && SolveProblem(map.at(x - 1, y), path+"L"));   //westen
    } catch (exception &e) {
        cerr << e.what();
    }
    return false;
}

const Labyrinth &Solver::getMap() const {
    return map;
}

const Coordinate &Solver::getCurrentPosition() const {
    return currentPosition;
}
