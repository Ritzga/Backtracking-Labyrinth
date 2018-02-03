#include <iostream>
#include <string>
#include <exception>
#include "Reader.h"
#include "Labyrinth.h"
#include "Coordinate.h"

#ifndef Solver_define
#define Solver_define

using namespace std;

class Solver {
public:
    //Konstruktor
    /**
     * @Brief Konstruktor für die Klasse Solver
     * @param fileName string: Zeichenkette für Pfad zur Datei und die Datei selbst
     * @param fastSolve bool: boolischer Wert ob das Labyrinth schnell oder langsam gelöst
     * @param graphicalSolve bool: ob die Lösung auch grafisch ausgegeben wird
     * werden soll. Es gibt keinen default Konstruktor für diese Klasse deshalb muss immer eine
     * Datei und einen boolischen Wert als Parameter benutzt werden.
     */
    Solver(const string &fileName, bool graphicalSolve);

    //Methoden
    /**
     * @Brief Diese Methode ist für das Lösen der Labyrinthe zuständig
     * Anhand der Startposition, wird in Norden, Osten, Westen und Süden geprüft ob ein Weg möglich
     * ist. Wenn ein Weg möglich ist, so wird dieser als Rekursion aufgerufen und das es wird erneut
     * geprüft ob Wege vorhanden sind. Mit Hilfe der Methode "pathExists" wird herausgefunden,
     * ob der Weg passierbar ist, schon benutzt wurde oder sich dort eine Wand befindet.
     * Ist die aktuelle Position die der Endposition so wird der Weg zurückgegeben, welcher Rekursiv
     * aufgestellt wird (path). Darüber hinaus wird der boolische Wert "isSolved" auf wahr gesetzt,
     * um damit weitere rekursive Aufrufe zu verhindern.
     * @param position Coordinate: Momentane Position des Solvers in dem Labyrinth
     * @param path string: Pfad der generiert wird, und als Lösung zurückgegeben wird
     * @return bool: gibt einen boolischen Wert, ob der Pfad Ungültig ist, oder das Labyrint gelöst
     * wurde.
     */
    bool SolveProblem(Coordinate &position, string path);

    //Getter und Setter
    /**
     * @Brief Dies ist der Getter für das Attribut currentPosition der Klasse Coordinate
     * Hierbei handelt es sich um eine ganz normale Getter Methode um an das private Attribut
     * "currentPosition" der Klasse Coordinate
     * @return Coordinate: gibt die Coordinaten der momentanen Position zurück
     */
    const Coordinate &getCurrentPosition() const;
    /**
     * @Brief gibt zurück ob Labyrinth gelöst wurde
     * Dies ist ein Getter für die Variable "isSolved" und gibt einen Wahrheitswert zurück
     * ob das Labyrinth gelöst wurde oder nicht.
     * @return bool: Ob Labyrinth gelöst wurde
     */
    bool getIsSolved() const;
    /**
     * @Brief gibt einen boolischen Wert zurück, ob Fehler aufgetreten sind oder nicht
     * Dies ist eine Getter Methode, ob Fehler aufgetreten sind.
     * @return bool: Ob Fehler aufgetreten sind
     */
    bool isException() const;

private:
    //Methode
    /**
     * @Brief Testet ob ein bestimmtes Feld im Labyrinth existiert
     * Hierbei wird zuerst geprüft ob X größer 0 und kleiner gleich die breite des Labyrinthes ist.
     * Danach wird geprüft ob Y wie X kleiner 0 und kleiner gleich der Höhe ist
     * @param x unsigned int: X Wert des Feldes, dass geprüft werden soll
     * @param y unsigned int: Y Wert des Feldes, dass geprüft werden soll
     * @return bool: gibt einen boolischen Wert zurück, der darüber aussagt, ob es ein Feld gibt
     *               oder nicht
     */
    bool pathExists(unsigned int x, unsigned int y);

    //Attribute
    //Beinhaltet das Labyrinth, welche vom Reader generiert wurde
    Labyrinth map;
    //Ob das Lösen des Labyrinth in der Konsole angezeigt werden soll (grafische Darstellung)
    bool graphicalSolve = false;
    //Boolischer Wert, der angibt ob das Labyrinth bereits gelöst ist
    bool isSolved = false;
    //Ob ein Fehler aufgetreten ist
    bool exception = false;
    //gibt an, wo sich der Solver auf der Karte befindet
    Coordinate currentPosition;
};
#endif
