#include <vector>
#include <string>
#include <iostream>
#include <ostream>
#include "Coordinate.h"

#ifndef Labyrinth_define
#define Labyrinth_define

using namespace std;

class Labyrinth {
public:
    //Konstruktor
    Labyrinth() = default;

    //Methoden
    friend ostream &operator<<(ostream &os, const Labyrinth &labyrinth);

    //Getter und Setter Methoden
    unsigned int getHeight() const;
    void setHeight(unsigned int height);
    unsigned int getWidth() const;
    void setWidth(unsigned int width);
    const Coordinate &getStartPoint() const;
    void setStartPoint(const Coordinate &startPoint);
    const Coordinate &getEndPoint() const;
    void setEndPoint(const Coordinate &endPoint);
    void setMap(vector<vector<Coordinate>> &map);
    const vector<vector<Coordinate>> &getMap();

    void setUsedPathAt(Coordinate &coordinate, bool &usedPath);

    Coordinate & at(unsigned int x, unsigned int y);
    Coordinate & at(Coordinate & coordinate);

private:
    //2D Vector des Labyrinthes
    vector<vector<Coordinate>>map;
    //Breite des Labyrinthes
    unsigned int width = 0;
    //Höhe des Labyrinthes
    unsigned int height = 0;
    //Startpunkt des Lapyrinthes
    Coordinate startPoint = Coordinate(0,0,false);
    //Endpunkt des Labyrinthes
    Coordinate endPoint = Coordinate(0,0,false);
};
#endif