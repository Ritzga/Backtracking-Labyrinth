#ifndef Coordinate_define
#define Coordinate_define

#include <stdint-gcc.h>
#include <ostream>

class Coordinate {
public:
    //Konstruktor
    Coordinate() = default;
    Coordinate(unsigned int x, unsigned int y);
    Coordinate(unsigned int x, unsigned int y, bool walkable);

    //Methoden
    bool operator==(const Coordinate &rhs) const;
    bool operator!=(const Coordinate &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate);

    void initialize(unsigned int x, unsigned int y, bool walkable);

    //Getter und Setter
    bool isUsedPath() const;
    void setUsedPath(bool usedPath);
    unsigned int getX();
    void setX(unsigned int x);
    unsigned int getY();
    void setY(unsigned int y);
    bool isWalkable() const;
    void setWalkable(bool walkable);
private:
    //X Koordinate des Feldes
    unsigned int x = 0;
    //Y Koordinate des Feldes
    unsigned int y = 0;
    //Ist Feld betrettbar
    bool walkable = false;
    //Wurde Feld betretten
    bool usedPath = false;
};
#endif