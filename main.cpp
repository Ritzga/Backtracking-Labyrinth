#include <iostream>
#include "Solver.h"

using namespace std;

int main()
{
    Solver solver = Solver("../labyrinth.txt", false);
    cout << solver.getMap();
    Coordinate position = solver.getCurrentPosition();
    solver.SolveProblem(position);
    return 0;
}