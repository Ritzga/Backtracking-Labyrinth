#include "Labyrinth.h"

unsigned int Labyrinth::getHeight() const {
    return height;
}

void Labyrinth::setHeight(unsigned int height) {
    Labyrinth::height = height;
}

unsigned int Labyrinth::getWidth() const {
    return width;
}

void Labyrinth::setWidth(unsigned int width) {
    Labyrinth::width = width;
}

const Coordinate &Labyrinth::getStartPoint() const {
    return startPoint;
}

void Labyrinth::setStartPoint(const Coordinate &startPoint) {
    Labyrinth::startPoint = startPoint;
}

const Coordinate &Labyrinth::getEndPoint() const {
    return endPoint;
}

void Labyrinth::setEndPoint(const Coordinate &endPoint) {
    Labyrinth::endPoint = endPoint;
}

void Labyrinth::setMap(vector<vector<Coordinate>> &map) {
    Labyrinth::map = map;
}

const vector<vector<Coordinate>> &Labyrinth::getMap() {
    return map;
}

ostream &operator<<(ostream &os, const Labyrinth &labyrinth) {
    string fields;
    for (const auto &i : labyrinth.map) { //foreach-schleife
        for (auto &j : i) { //Innere foreach-schleife
            if(j.isWalkable())
            {
                if(j.isUsedPath())
                {
                    fields += ".";
                }
                else
                {
                    fields += " ";
                }
            }
            else
            {
                fields += "*";
            }
        }
        fields += "\n";
    }
    os << fields;
    return os;
}
