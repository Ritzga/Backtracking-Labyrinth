#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Coordinate.h"
#include "Labyrinth.h"

#ifndef Reader_define
#define Reader_define

using namespace std;

class Reader {
public:
    Reader(const string &fileName);
    Labyrinth readMap();
    //Getter und Setter
    const Labyrinth &getMap() const;

private:
    //Dateiname (welche sich im gleichen Ordner befinden muss!)
    string fileName;
    Labyrinth map;
};
#endif
