#include "Solver.h"

Solver::Solver(const string &fileName, bool fastSolve)
: fastSolve(fastSolve)
{
    Reader generator = Reader(fileName);
    map = generator.getMap();
    currentPosition = map.getStartPoint();
}

void Solver::setCurrentPosition(const Coordinate &currentPosition) {
    Solver::currentPosition = currentPosition;
}

bool Solver::pathExists(Coordinate position) {
    //prüft ob es das Feld überhaupt gibt
    if(position.getX() < 0 || position.getX() > map.getWidth())
    {
        return false;
    }
    else if(position.getY() < 0 || position.getY() > map.getHeight())
    {
        return false;
    }
    return map.getMap().at(position.getY()).at(position.getX()).isWalkable();
}

bool Solver::SolveProblem(Coordinate position) {
    //Positionen werden auf Begehbarkeit abhängig der Position geprüft
    cout << position;
    //Setzt den Punkt als benutzt
    map.getMap().at(position.getY()).at(position.getX());

    if(map.getEndPoint() == position)
    {
        cout << "GESCHAAAAAFT";
        return true;
    }
    if(pathExists(Coordinate(position.getX(), position.getY()+1))) //y+1
    {
        SolveProblem(Coordinate(position.getX(), position.getY()+1));
    }
    if(pathExists(Coordinate(position.getX()+1, position.getY()))) //x+1
    {
        SolveProblem(Coordinate(position.getX()+1, position.getY()));
    }
    if(pathExists(Coordinate(position.getX(), position.getY()-1))) //y-1
    {
        SolveProblem(Coordinate(position.getX(), position.getY()-1));
    }
    if(pathExists(Coordinate(position.getX()-1, position.getY()))) //x-1
    {
        SolveProblem(Coordinate(position.getX()-1, position.getY()));
    }
    return false;
}

const Labyrinth &Solver::getMap() const
{
    return map;
}

const Coordinate &Solver::getCurrentPosition() const {
    return currentPosition;
}