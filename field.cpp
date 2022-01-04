//
// Created by evren on 4.01.2022.
//

#include <iostream>
#include <sstream>
#include "field.h"

field::field(parseFile *parsedFile) {
    this->parsedFile = parsedFile;
    this->createMapField();
}

void field::createMapArray() {
    this->map = (int**)calloc(this->parsedFile->fieldSize[0], sizeof(int*));
    for (int i = 0; i < this->parsedFile->fieldSize[0]; i++) {
        this->map[i] = (int*)calloc(this->parsedFile->fieldSize[1], sizeof(int));
    }
}

void field::createMapField() {
    this->createMapArray();

    for (int i= 1; i < this->parsedFile->rowCount; i++) {
        int tempRowData[4] = {-1, -1, -1, -1};

        std::stringstream rowData(this->parsedFile->content[i]);
        for (int j = 0; j < 4; j++) {
            if (rowData.good())
                rowData >> tempRowData[j];
        }

        // if 3rd or 4th is not set, it means that the row is year data
        if (tempRowData[2] == -1 || tempRowData[3] == -1) {
            this->decreaseAllFields();
        } else {
            // process the data to field

            int initialCoordinate[2] = {tempRowData[0], tempRowData[1]};
            int finalCoordinate[2] = {tempRowData[2], tempRowData[3]};

            this->processTheField(initialCoordinate, finalCoordinate);
        }
    }
    this->decreaseAllFields();
}

void field::decreaseAllFields() {
    for (int i = 0; i < this->parsedFile->fieldSize[0]; i++) {
        for (int j = 0; j < this->parsedFile->fieldSize[1]; j++) {
            if (this->map[i][j] != 0)
                this->map[i][j]--;
        }
    }
}

void field::processTheField(int initialCoordinate[2], int finalCoordinate[2]) {
    int i, j;
    for (i = initialCoordinate[0]; i <= finalCoordinate[0]; i++) {
        for (j = initialCoordinate[1]; j <= finalCoordinate[1]; j++) {
            this->map[i][j] += 2;
        }
    }
}

void field::renderMap() {
    for (int i = 0; i < this->parsedFile->fieldSize[1]; i++) {
        for (int j = 0; j < this->parsedFile->fieldSize[0]; j++) {
            std::cout << this->map[j][i] << " ";
        }
        std::cout << std::endl;
    }
}