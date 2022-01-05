//
// Created by evren on 4.01.2022.
//

#ifndef FINALPROJECT_FIELD_H
#define FINALPROJECT_FIELD_H

#include "parseFile.h"

class field {
public:
    parseFile *parsedFile;
    field(parseFile *parsedFile);
    void renderMap();
private:
    int** map;
    void createMapArray();
    void decreaseAllFields();
    void processTheField(int initialCoordinate[2], int finalCoordinate[2]);
    void createMapField();
};


#endif //FINALPROJECT_FIELD_H
