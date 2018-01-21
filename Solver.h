#include <iostream>
#include <string>
#include "Reader.h"
#include "Labyrinth.h"
#include "Coordinate.h"

#ifndef Solver_define
#define Solver_define

using namespace std;

class Solver {
public:
    //Konstruktor
    Solver(const string &fileName, bool fastSolve);

    //Methoden
    bool SolveProblem(Coordinate &position);

    //Getter und Setter
    const Labyrinth &getMap() const;
    const Coordinate &getCurrentPosition() const;
    void setCurrentPosition(const Coordinate &currentPosition);

private:
    //Methode
    bool pathExists(unsigned int x, unsigned int y);

    //Attribute
    Labyrinth map;
    bool fastSolve;
    Coordinate currentPosition;
};
#endif