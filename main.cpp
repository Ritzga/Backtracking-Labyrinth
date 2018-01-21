#include <iostream>
#include "Solver.h"

using namespace std;

int main()
{
    Solver solver = Solver("labyrinth.txt", false);
    cout << solver.getMap();
    solver.SolveProblem(solver.getCurrentPosition());
    return 0;
}