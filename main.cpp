#include <iostream>
#include "Solver.h"

using namespace std;

int main()
{
    string fileName;
    char fastSolve;
    cout << "Lybrinth löser!\nLabyrinth einlesen (Die Datei muss sich im Ordner des Programms befinden):";
    cin >> fileName;
    do
    {
        cout << "\nSoll das Lybrinth schnell oder langsam (betrachtbar) gelöst werden ? (J/N):";
        cin >> fastSolve;
    } while(fastSolve != 'J' && fastSolve != 'N');

    Solver solver = Solver(fileName, fastSolve != 'N');
    cout << solver.getMap();
    Coordinate position = solver.getCurrentPosition();
    solver.SolveProblem(position, "");
    return 0;
}
