#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Coordinate.hpp"
#include "Labyrinth.hpp"

#ifndef Reader_define
#define Reader_define

using namespace std;

class Reader {
public:
    /**
     * @Brief Konstruktor für die Klasse Reader
     * Hier wird das Labyrinth mit hilfe der Methode readMap in das Attribut map gespeichert.
     * @param fileName string: Datei welche eingelesen werden soll
     */
    Reader(const string &fileName);
    /**
     * @Brief Methode zum einlesen eines Labyrinthes aus einer Datei in eine Objekt der Klasse
     *        Labyrinth
     * Es wird versucht die vom Benutzer eingebene Datei zu öffnen, wenn die Datei nicht gefunden
     * werden kann, so wird ein Laufzeitfehler ausgebenen und das Programm geschlosen. Wenn die
     * Datei gefunden werden kann, so wird sie Zeile für Zeile ausgelesen. Zuerst wird ein Stringstream
     * initialisiert der die größe des Labyrinthes ausliest, dann den Start/Endpunkt und dann das
     * eigentliche Labyrinth. Vor dem Auslesen wird ein Objekt der Klasse Labyrinth mit dem default
     * Konstruktor initialisiert und dann mit den ausgelesenen Werten defniert.
     * In der TEST.txt werden alle Fehler demonstriert die abgefangen werden können.
     * @return Labyrinth: Generiertes Labyrinth, welches ausgelesen wurde
     */
    Labyrinth readMap();
    //Getter und Setter
    /**
     * @Brief Getter Methode für die Karte (Labyrinth)
     * Dieser Getter dient dazu, dass das Solver-objekt die Karte vom Reader objekt bekommt.
     * @return Labyrinth: gibt das Attribut map aus
     */
    const Labyrinth &getMap() const;
    /**
     * @Brief Getter Methode für exception
     * Boolische Variable, welche wenn sie auf wahr ist, auf einen Fehler beim auslesen vermerkt.
     * @return bool: gibt den Wahrheitswert zurück
     */
    bool isException() const;

private:
    //Dateiname (welche sich im gleichen Ordner befinden muss!)
    string fileName;
    //Das Labyrinth, welches Ausgelesen wurde
    Labyrinth map;
    //Wichtig, wenn ein Fehler aufgetreten ist damit es nicht zu Fehlern kommt (wenn es wahr ist,
    //ist ein Fehler aufgetreten
    bool exception = false;
};
#endif
