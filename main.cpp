#include <iostream>
#include "Solver.h"

using namespace std;

int main()
{
    string fileName;
    char graphicalSolve;
    cout << "Laybrinth-Löser\nLabyrinth einlesen (vollständiger Pfad mit Datei \n"
            "oder wenn sie im gleichen Ordner ist, nur die Datei):";
    cin >> fileName;
    do
    {
        cout << "\nSoll die Lösung des labyrinthes grafisch angezeigt werden? (J/N):";
        cin >> graphicalSolve;
    } while(graphicalSolve != 'J' && graphicalSolve != 'N');

    //Erstellt das Solver Objekt, welches das Labyrinth löst
    Solver solver = Solver(fileName, graphicalSolve != 'N');
    if(!solver.isException())
    {
        Coordinate position = solver.getCurrentPosition();
        solver.SolveProblem(position, "");
        if(solver.getIsSolved())
        {
            cout << "\nLeider konnte das Labyrinth nicht gelöst werden.";
        }
    }
    else
    {
        cout << "\nEs ist ein unbekannter Fehler aufgetreten!";
    }
    return 0;
}
