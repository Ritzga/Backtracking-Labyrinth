#include "Reader.h"

Labyrinth Reader::readMap()
{
    Labyrinth generatedMap;
    try
    {
        string currentRow; //Variable für die ausgelesene Zeile
        unsigned int height, width; //Variablen für das auslesen der H/B
        unsigned int x, y; //Variablen für x/y
        ifstream file(fileName);

        //Breite und höhe des Labyrinthes
        getline(file, currentRow);
        stringstream sstream (currentRow);
        sstream >> height >> width;
        generatedMap.setHeight(height);
        generatedMap.setWidth(width);
        //Debug
        //cout << "Höhe: " << generatedMap.getHeight() << " Breite: " << generatedMap.getWidth() << "\n";

        //Startpunkt
        getline(file, currentRow);
        stringstream sstreamStartpoint (currentRow);
        sstreamStartpoint >> y >> x;
        generatedMap.setStartPoint(Coordinate(x, y, true));
        //Debug
        //cout << "Startpunkt: " << generatedMap.getStartPoint().getX() << " " << generatedMap.getStartPoint().getY() << "\n";

        //Endpunkt
        getline(file, currentRow);
        stringstream sstreamEndpiont (currentRow);
        sstreamEndpiont >> y >> x;
        generatedMap.setEndPoint(Coordinate(x, y, true));
        //Debug
        //cout << "Endpunkt: " << generatedMap.getEndPoint().getX() << " " << generatedMap.getEndPoint().getY() << "\n";

        //Variablen für das auslesen des tatsächlichen Labyrinthes
        unsigned int yAsRow = 0;
        //2D Vector mit der höhe und der breite des Labyrinthes
        vector<vector<Coordinate>> mapPoints (vector<vector<Coordinate> >(generatedMap.getWidth(), vector<Coordinate>(generatedMap.getHeight())));

        while (getline(file, currentRow))
        {
            //Auslesen des Labyrinthes
                //cout << currentRow << " Labyrinth\n"; //Debug
                for(unsigned int xAsColumn=0; xAsColumn < currentRow.size(); xAsColumn++)
                {
                    mapPoints.at(xAsColumn).at(yAsRow).initialize(xAsColumn,yAsRow, currentRow[xAsColumn] != '*');
                }
                yAsRow++;
        }
        file.close();

        generatedMap.setMap(mapPoints);
    }
    catch (ifstream::failure &e) {
        cout << "Datei " << fileName << " konnte nicht eingelesen werden: " << e.what();
    }
    return generatedMap;
}

Reader::Reader(const string &fileName)
: fileName(fileName)
{
    map = readMap();
}

const Labyrinth &Reader::getMap() const {
    return map;
}
