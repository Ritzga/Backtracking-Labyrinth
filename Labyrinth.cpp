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

Coordinate &Labyrinth::at(Coordinate &coordinate) {
    unsigned int x = coordinate.getX();
    unsigned int y = coordinate.getY();
    return at(x, y);
}

Coordinate & Labyrinth::at(unsigned int x, unsigned int y) {
    return map.at(x).at(y);
}

const Coordinate & Labyrinth::at(unsigned int x, unsigned int y) const {
    return map.at(x).at(y);
}

void Labyrinth::setUsedPathAt(Coordinate &coordinate, bool &usedPath) {
    this->at(coordinate).setUsedPath(usedPath);
}

void Labyrinth::setMap(vector<vector<Coordinate>> &map) {
    this->map = map;
}

const vector<vector<Coordinate>> &Labyrinth::getMap() {
    return map;
}

ostream &operator<<(ostream &os, const Labyrinth &labyrinth) {
    string fields = " ";
    const Coordinate *coordinate = nullptr;
    for (unsigned int x = 0; x < labyrinth.getWidth(); ++x) { //spalteniteration
        fields+= std::to_string(x);
    }
    fields += "\n";
    for (unsigned int y = 0; y < labyrinth.getHeight(); ++y) { //zeileniteration
        fields += std::to_string(y);
        for (unsigned int x = 0; x < labyrinth.getWidth(); ++x) { //spalteniteration
            coordinate = &labyrinth.at(x,y);
            if(coordinate->isWalkable())
            {
                if(coordinate->isUsedPath())
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

