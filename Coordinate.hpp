#ifndef Coordinate_define
#define Coordinate_define
#include <ostream>

class Coordinate {
public:
    /**
     * @Brief Default Konstruktor von Coodinate
     * Dies ist der Default Konstruktor von Coodinate und erzeugt ein Objekt der Klasse
     * Coordinate den Standartwerten: x=0,y=0,walkable=false,usedPath=false
     */
    Coordinate() = default;

    /**
     * @Brief Überladener Konstruktor von Coordinate
     * Dieser Konstruktor nihmt X und Y Coordinaten an und lässt dabei
     * walkable=false und usedPath=false
     * @param x unsigned int: übergebene X Koordinate
     * @param y unsigned int: übergebene Y Koordinate
     */
    Coordinate(unsigned int x, unsigned int y);

    /**
     * @Brief Überladener Konstruktor von Coordinate
     * Dieser Konstruktor nihmt X,Y Coordinaten und einen boolischen Wert walkable an und
     * lässt dabei usedPath=false. Dieser Konstruktor wird im Reader benutzt um Felder in einen
     * vector einspeichern.
     * @param x unsigned int: übergebene X Koordinate
     * @param y unsigned int: übergebene Y Koordinate
     * @param walkable bool: Ob das Feld begehbar ist oder nicht
     *
     */
    Coordinate(unsigned int x, unsigned int y, bool walkable);

    //Methoden
    /**
     * @Brief Operator-Überladung des == Operators um Koordinaten zu vergleichen
     * Vergleicht die Koordinaten des eigenen Objektes mit dem eines anderen Objektes der Klasse
     * Coordinaten
     * @param rhs Coordinate: Das mit dem zu Vergleichende Objekt der Klasse Coordinate
     * @return bool: gibt einen boolischen Wert zurück, ob beide Objekte die selben Koordinaten
     * haben
     */
    bool operator==(const Coordinate &rhs) const;

    /**
     * @Brief Operator-Überladung des != Operators um Koordinaten zu vergleichen
     * Vergleicht die Koordinaten des eigenen Objektes mit dem eines anderen Objektes der Klasse
     * Coordinaten
     * @param rhs Coordinate: Das mit dem zu Vergleichende Objekt der Klasse Coordinate
     * @return bool: gibt einen boolischen Wert zurück, ob beide Objekte nicht die selben
     * Koordinaten haben
     */
    bool operator!=(const Coordinate &rhs) const;

    /**
     * @Brief Gibt eine Koordinate in die Konsole aus
     * Bei dieser Ausgabe werden die X und Y Koordinaten des Objektes ausgegeben
     * @param os outstream: Ausgabestrom in den geschrieben wird
     * @param coordinate Coordinate: Koordinate die ausgegeben werden soll
     * @return outstream: der Outstream wird wieder ausgeben
     */
    friend std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate);

    /**
     * @Brief Initialisiert eine der Objekt der Coordinate
     * Diese Methode wird bentutzt um ein deklariertes Objekt, welche keine Werte beinhaltet,
     * mit Werten zu defnieren.
     * @param x unsigned int: X Wert den die Koordinate haben soll
     * @param y unsigned int: Y Wert den die Koordinate haben soll
     * @param walkable bool: Ob das Feld betretbar sein soll oder nicht
     */
    void initialize(unsigned int x, unsigned int y, bool walkable);

    //Getter und Setter
    /**
     * @Brief Gibt zurück ob der Weg bereits benutzt ist
     * Dies ist eine Getter Methode für usedPath
     * @return bool: ob der Weg schon einmal benutzt worden ist oder nicht
     */
    bool isUsedPath() const;
    /**
     * @Brief Setzt das Feld der momentanen Position
     * Dieser Setter wird dazu benutzt um Felder auf "benutzt" setzt, damit der Algorythmus nicht
     * nochmal auf das Feld läuft.
     * @param usedPath bool: der Wahrheitswert auf dass das Feld gesetzt wird
     */
    void setUsedPath(bool usedPath);
    /**
     * @Brief Gibt die X-Coordinate des Feldes zurück
     * Dies ist eine Getter Methode für x
     * @return unsigned int: X-Coordinate des Feldes
     */
    unsigned int getX();
    /**
     * @Brief Gibt die Y-Coordinate des Feldes zurück
     * Dies ist eine Getter Methode für y
     * @return unsigned int: Y-Coordinate des Feldes
     */
    unsigned int getY();
    /**
     * @Brief gibt zurück ob Feld begehbar ist oder ob es eine Wand ist
     * Dies ist eine Getter Methode für "walkable"
     * @return gibt den Wert des Feldes zurück
     */
    bool isWalkable() const;

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
