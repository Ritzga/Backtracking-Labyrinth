#include "Reader.hpp"

Reader::Reader(const string &fileName)
        : fileName(fileName)
{
    try
    {
        map = readMap();
    }
    catch (runtime_error &e)
    {
        exception = true;
        cout << e.what();
    }
}

Labyrinth Reader::readMap()
{
    Labyrinth generatedMap;
    string currentRow; //Variable für die ausgelesene Zeile
    unsigned int height, width; //Variablen für das auslesen der H/B
    unsigned int x, y; //Variablen für x/y
    ifstream file(fileName);
    if(!file)
    {
        throw runtime_error("\nFehler: Datei konnte nicht gefunden werden!");
    }

    //Breite und höhe des Labyrinthes
    getline(file, currentRow);
    stringstream sstream (currentRow);
    sstream >> height >> width;
    generatedMap.setHeight(height);
    generatedMap.setWidth(width);
    //Debug
    //cout << "Höhe: " << generatedMap.getHeight() << " Breite: " << generatedMap.getWidth() << "\n";

    //Fehlerbehandlung der Höhe und Breite
    if(height == 0 || width == 0)
    {
        throw runtime_error("\nFehler: Die Höhe und die Breite des Labyrinthes sind 0, somit ist das Labyrinth fehlerhaft aufgebaut!");
    }

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

    //Fehlerbehandlung vom Start/Endpunkt
    if(generatedMap.getEndPoint() == Coordinate(544,0) && generatedMap.getStartPoint() == Coordinate(544,0))
    {
        throw runtime_error("\nDer End- und Startpunkt wurden nicht definiert, somit wurde des Labyrinth fehlerhaft aufgebaut!");
    }
    if(generatedMap.getEndPoint() == generatedMap.getStartPoint())
    {
        throw runtime_error("\nDer Start/Endpunkt liegen auf dem selben Feld, somit wurde des Labyrinth fehlerhaft aufgebaut!");
    }

    //Variablen für das auslesen des tatsächlichen Labyrinthes
    unsigned int yAsRow = 0;
    //2D Vector mit der höhe und der breite des Labyrinthes
    vector<vector<Coordinate>> mapPoints (vector<vector<Coordinate> >(generatedMap.getWidth(), vector<Coordinate>(generatedMap.getHeight())));

    //Fehlervariable fals kein offenes Feld vorhanden ist
    unsigned int existsWalkable = 0;
    while (getline(file, currentRow))
    {
        //Auslesen des Labyrinthes
        //cout << currentRow << " Labyrinth\n"; //Debug
        //Wenn nach der 4. Zeile nichts geschrieben wurde, wird ein Fehler ausgebenen
        if(currentRow.empty())
        {
            throw runtime_error("\nEs konnten keine Felder gefunden werden, somit wurde das Labyrinth fehlerhaft aufgebaut!");
        }
        //Wenn das Labyrinth nich so breit ist als angegeben
        if(currentRow.size() < generatedMap.getWidth())
        {
            throw runtime_error("\nDas Labyrinth ist weniger breit als angegeben, somit wurde das Labyrinth fehlerhaft aufgebaut!");

        }
        //Wenn das Labyrinth breiter ist als angegeben
        if(currentRow.size() > generatedMap.getWidth())
        {
            throw runtime_error("\nDas Labyrinth ist breiter als angegeben, somit wurde das Labyrinth fehlerhaft aufgebaut!");
        }
        for(unsigned int xAsColumn=0; xAsColumn < currentRow.size(); xAsColumn++)
        {
            if(currentRow[xAsColumn] != '*')
            {
                existsWalkable++;
            }
            if(xAsColumn > generatedMap.getWidth()-1)
            {
                throw runtime_error("\nDas Labyrinth ist breiter als angegeben, somit wurde das Labyrinth fehlerhaft aufgebaut!");
            }
            mapPoints.at(xAsColumn).at(yAsRow).initialize(xAsColumn,yAsRow, currentRow[xAsColumn] != '*');
        }
        yAsRow++;
    }
    //Fehlerbehandlungen
    //Wenn das Labyrinth zu klein ist
    if(yAsRow < generatedMap.getHeight())
    {
        throw runtime_error("\nDas Labyrinth ist kleiner in der Höhe als angegeben, somit wurde das Labyrinth fehlerhaft aufgebaut!");
    }
    //Wenn es keine begehbaren Felder gibt
    if(existsWalkable == 0)
    {
        throw runtime_error("\nEs gibt kein begehbares Feld im Labyrinth, somit wurde das Labyrinth fehlerhaft aufgebaut!");
    }
    file.close();

    generatedMap.setMap(mapPoints);
    return generatedMap;
}

const Labyrinth &Reader::getMap() const
{
    return map;
}

bool Reader::isException() const {
    return exception;
}
