#include <vector>
#include <string>
#include <iostream>
#include <ostream>
#include "Coordinate.hpp"

#ifndef Labyrinth_define
#define Labyrinth_define

using namespace std;

class Labyrinth {
public:
    /**
     * @Brief Default Konstruktor von Labyrinth
     * Dies ist der Default Konstruktor von Labyrinth und erzeugt ein Objekt der Coordinate mit
     * den Standartwerten: leeren 2D vector,Start und Endpunkt sind bei (0,0) und höhe und breite
     * sind 0
     */
    Labyrinth() = default;

    //Methoden
    /**
     * @Brief Ausgabe-Überladung für das Labyrinth
     * Hierbei wird der 2D vector (map) ausgelesen und das dabei entstehende Labyrinth in der
     * Konsole ausgeben. Dabei wird ein leeres Feld mit " ", eine Wand mit "*" und ein bereits
     * verwendeter Weg mit "." makiert.
     * @param os outstream: der Outputstream der Konsole
     * @param Labyrinth: Das Labyrinth, welches ausgelesen werden soll
     * @return outstream: gibt den Outputstream mit dem eingebenen werten zuück
     */
    friend ostream &operator<<(ostream &os, const Labyrinth &labyrinth);

    //Getter und Setter Methoden
    /**
     * @Brief Dies ist der Getter für das Attribut height der Klasse Labyrinth
     * Ruft die Höhe des Labyrinthes ab und gibt diese nach Außen (außerhalb des Objektes)
     * @return unsigned int: höhe des Labyrinthes
     */
    unsigned int getHeight() const;
    /**
     * @Biref Dies ist der Setter für das Attribut height der Klasse Labyrinth
     * Setzt den Wert für die Höhe des Labyrinthes, auch von außerhalb des Objektes
     * @param height unsigned int: die geplannte Höhe des Labyrinthes
     */
    void setHeight(unsigned int height);
    /**
     * @Brief Dies ist der Getter für das Attribut width der Klasse Labyrinth
     * Ruft den Wert der Breite des Labyrinthes ab und gibt ihn als Zahlenwert zurück
     * @return unsigned int: die breite des Labyrinthes
     */
    unsigned int getWidth() const;
    /**
     * @Brief Dies ist der Setter für das Attribut width der Klasse Labyrinth
     * Legt den geplannten Wert für die Breite des Labyrinthes fest
     * @param width unsigned int: breite die das Labyrinth haben soll
     */
    void setWidth(unsigned int width);
    /**
     * @Brief Dies ist der Getter für das Attribut startPoint der Klasse Labyrinth
     * Gibt die Koordinaten des Startpunktes als Objekt der Klasse Coordinate zurück
     * @return Objekt der Klasse Coordinate, welches die Koordinaten des Startpunktes beinhalten
     */
    const Coordinate &getStartPoint() const;
    /**
     * @Brief Dies ist der Setter für das Attribut startPoint der Klasse Labyrinth
     * Legt den Startpunkt des Labyrinthes fest mit hilfe eines Coordinaten Objektes
     * @param startPoint Coordinate: Objekt der Klasse Coordinate, welches die Koordinaten des
     *                               Startpunktes sind
     */
    void setStartPoint(const Coordinate &startPoint);
    /**
     * @Brief Dies ist der Getter für das Attribut endPoint der Klasse Labyrinth
     * Ruft den Wert des Endpunktes ab und gibt ein Objekt der Klasse Coordinaten zurück
     * welches den Endpunkt als X,Y Wert beinhaltet
     * @return
     */
    const Coordinate &getEndPoint() const;
    /**
     * @Brief Dies ist der Setter für das Attribut endPoint der Klasse Labyrinth
     * Legt den Wert für den Endpunkt fest
     * @param endPoint Coordinate: Objekt der Klasse Coordinate, welche den Endpunkt beinhaltet
     *
     */
    void setEndPoint(const Coordinate &endPoint);
    /**
     * @Brief Dies ist der Setter für das Attribut map der Klasse Labyrinth
     * Der 2D Vector wird mit Coordinaten gefüllt, welche alle Felder auf dem Labyrinth
     * repräsentieren.
     * @param map vector<vector<Coordinate>>: 2D Vector der aus Coordinaten Objekten bestehen
     */
    void setMap(vector<vector<Coordinate>> &map);
    /**
     * @Brief gibt ein Objekt der Klasse Coordinate zurück
     * Diese Coordinate kann über das Attribut map angesteuert werden, mit dieser Mehtode wird
     * das auslesen und das setzen der Werte erleichtert und funktioniert prinzipel wie die
     * normale at() Methode
     * @param x unsigned int: positions Wert X des Feldes auf der Karte (Labyrinth)
     * @param y unsigned int: positions Wert Y des Feldes auf der Karte (Labyrinth)
     * @return gibt das exakte Coordinaten Objekt des Feldes zurück
     *
     */
    Coordinate &at(unsigned int x, unsigned int y);
    /**
     * @Brief Dies ist ledeglich eine const version der normalen "&at" Methode
     * (siehe Coordinate &at)
     */
    const Coordinate &at(unsigned int x, unsigned int y) const;
    /**
     * @Brief gibt ein Objekt der Klasse Coordinate zurück
     * Wie auch bei der vorherigen Methode soll diese hier den Zugriff auf die einzelnen Felder
     * erleichtern, hierbei werden keine X,Y benötigt, sondern nur die Koordinate an sich,
     * somit ist es möglich über ein Objekt der Klasse Coordinate an die Position eines Feldes
     * in der Karte (Labyrinth) zu kommen.
     * @param coordinate Coordinate: Koordinate an dem das Feld aufgerufen werden soll
     * @return gibt das exakte Coordinaten Objekt des Feldes zurück
     *
     */
    Coordinate &at(Coordinate &coordinate);

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
