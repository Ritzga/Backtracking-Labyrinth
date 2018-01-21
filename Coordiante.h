#ifndef AOPPRUEFUNG_TEST_H
#define AOPPRUEFUNG_TEST_H

class Coordiante {
public:
    Coordiante(unsigned int x, unsigned int y, bool walkable);

    //Getter und Setter
    void setXY(unsigned int x, unsigned int y);
    unsigned int getX() const;
    void setX(unsigned int x);
    unsigned int getY() const;
    void setY(unsigned int y);
    bool isWalkable() const;
    void setWalkable(bool walkable);
private:
    //X Koordinate des Feldes
    unsigned int x;
    //Y Koordinate des Feldes
    unsigned int y;
    //Ist Feld betrettbar oder nicht
    bool walkable;
};
#endif //AOPPRUEFUNG_TEST_H