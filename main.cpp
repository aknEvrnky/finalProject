#include <iostream>
#include <sstream>
#include "parseFile.h"

void decreaseAllFields(int** filedArea, int fieldSize[]) {
    for (int i = 0; i < fieldSize[0]; i++) {
        for (int j = 0; j < fieldSize[1]; j++) {
            if (filedArea[i][j] != 0)
                filedArea[i][j]--;
        }
    }
}

void processTheField(int** fieldArea, int initialCoordinate[2], int finalCoordinate[2]) {
    int i, j;
    for (i = initialCoordinate[0]; i <= finalCoordinate[0]; i++) {
        for (j = initialCoordinate[1]; j <= finalCoordinate[1]; j++) {
            fieldArea[i][j] += 2;
        }
    }
}

void printFiled(int** fieldArea, int fieldSize[2]) {
    for (int i = 0; i < fieldSize[1]; i++) {
        for (int j = 0; j < fieldSize[0]; j++) {
            std::cout << fieldArea[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {

    // get file directory from user

    std::string fileDirectory;
    fileDirectory = "C:\\Users\\evren\\Desktop\\finalProject\\fieldInfo1.txt";

    // read the file row by row
    parseFile parsedFile(fileDirectory);

    // get the size of field from first row


    // create dynamic field array

    int **fieldArea = (int**)calloc(parsedFile.fieldSize[0], sizeof(int*));
    for (int i = 0; i < parsedFile.fieldSize[0]; i++) {
        fieldArea[i] = (int*)calloc(parsedFile.fieldSize[1], sizeof(int));
    }

    // determine that the row includes area data or year data
    // and process the data accordingly

    for (int i= 1; i < parsedFile.rowCount; i++) {
        int tempRowData[4] = {-1, -1, -1, -1};

        std::stringstream rowData(parsedFile.content[i]);
        for (int j = 0; j < 4; j++) {
            if (rowData.good())
                rowData >> tempRowData[j];
        }

        // if 3rd or 4th is not set, it means that the row is year data
        if (tempRowData[2] == -1 || tempRowData[3] == -1) {
            decreaseAllFields(fieldArea, parsedFile.fieldSize);
        } else {
            // process the data to field

            int initialCoordinate[2] = {tempRowData[0], tempRowData[1]};
            int finalCoordinate[2] = {tempRowData[2], tempRowData[3]};

            processTheField(fieldArea, initialCoordinate, finalCoordinate);
        }
    }

    // decrease once again to get the final result
    decreaseAllFields(fieldArea, parsedFile.fieldSize);

    // print the field
    printFiled(fieldArea, parsedFile.fieldSize);

    return 0;
}
