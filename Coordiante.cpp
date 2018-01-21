#include "Coordiante.h"

unsigned int Coordiante::getX() const {
    return x;
}

void Coordiante::setX(unsigned int x) {
    Coordiante::x = x;
}

unsigned int Coordiante::getY() const {
    return y;
}

void Coordiante::setY(unsigned int y) {
    Coordiante::y = y;
}

bool Coordiante::isWalkable() const {
    return walkable;
}

void Coordiante::setWalkable(bool walkable) {
    Coordiante::walkable = walkable;
}

Coordiante::Coordiante(unsigned int x, unsigned int y, bool walkable)
: x(x), y(y), walkable(walkable)
{

}

void Coordiante::setXY(unsigned int x, unsigned int y) {
    this->x = x;
    this->y = y;
}
