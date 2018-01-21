#include "Coordinate.h"
Coordinate::Coordinate(unsigned int x, unsigned int y)
        : x(x), y(y)
{}

Coordinate::Coordinate(unsigned int x, unsigned int y, bool walkable)
        : x(x), y(y), walkable(walkable)
{}

unsigned int Coordinate::getX() {
    return x;
}

void Coordinate::setX(unsigned int x) {
    this->x = x;
}

unsigned int Coordinate::getY() {
    return y;
}

void Coordinate::setY(unsigned int y) {
    this->y = y;
}

bool Coordinate::isWalkable() const {
    return walkable;
}

void Coordinate::setWalkable(bool walkable) {
    Coordinate::walkable = walkable;
}

void Coordinate::initialize(unsigned int x, unsigned int y, bool walkable) {
    this->x = x;
    this->y = y;
    this->walkable = walkable;
}

bool Coordinate::isUsedPath() const {
    return usedPath;
}

void Coordinate::setUsedPath(bool usedPath) {
    Coordinate::usedPath = usedPath;
}

bool Coordinate::operator==(const Coordinate &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Coordinate::operator!=(const Coordinate &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate) {
    os << "x: " << coordinate.x << " y: " << coordinate.y << "\n";
    return os;
}
