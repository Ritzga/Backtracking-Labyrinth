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

bool Solver::pathExists(Coordinate position) {
    //prüft ob es das Feld überhaupt gibt
    if (position.getX() < 0 || position.getX() > map.getWidth()) {
        return false;
    } else if (position.getY() < 0 || position.getY() > map.getHeight()) {
        return false;
    }
    return map.getMap().at(position.getY()).at(position.getX()).isWalkable();
}

bool Solver::SolveProblem(Coordinate &position) {
    try {
        cout << map;
        //Positionen werden auf Begehbarkeit abhängig der Position geprüft
        cout << position;
        //Setzt den Punkt als benutzt
        position.setUsedPath(true);
        unsigned int x = position.getX();
        unsigned int y = position.getY();
        map.at(x, y);

        if (map.getEndPoint() == position) {
            cout << "GESCHAAAAAFT";
            return true;
        }
        return (pathExists(Coordinate(x, y + 1)) && SolveProblem(map.at(x, y + 1))) ||
               (pathExists(Coordinate(x + 1, y)) && SolveProblem(map.at(x + 1, y))) ||
               (pathExists(Coordinate(x, y - 1)) && SolveProblem(map.at(x, y - 1))) ||
               (pathExists(Coordinate(x - 1, y)) && SolveProblem(map.at(x - 1, y)));
    } catch (exception &e) {
        cerr << e.what();
    }
}

const Labyrinth &Solver::getMap() const {
    return map;
}

const Coordinate &Solver::getCurrentPosition() const {
    return currentPosition;
}