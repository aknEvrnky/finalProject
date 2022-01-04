#include <iostream>
#include <fstream>
#include <sstream>

int fileRowCount(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        count++;
    }
    file.close();
    return count;
}

void getFileContent(std::string fileDirectory, std::string content[]) {
    std::ifstream file(fileDirectory);
    std::string tempRow;
    int i = 0;
    while (std::getline(file, tempRow)) {
        content[i] += tempRow + "\n";
        i++;
    }
    file.close();
}

void getFieldSize(std::string row, int fieldSize[]) {
    std::stringstream stream(row);
    int i = 0;
    while (stream.good() && i < 2){
        stream >> fieldSize[i];
        i++;
    }
}

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

    std::string content[1000];
    getFileContent(fileDirectory, content);

    // get the size of field from first row

    int fieldSize[2];
    std::string firstRow = content[0];
    getFieldSize(firstRow, fieldSize);

    // create dynamic field array

    int **fieldArea = (int**)calloc(fieldSize[0], sizeof(int*));
    for (int i = 0; i < fieldSize[0]; i++) {
        fieldArea[i] = (int*)calloc(fieldSize[1], sizeof(int));
    }

    // determine that the row includes area data or year data
    // and process the data accordingly

    for (int i= 1; i < fileRowCount(fileDirectory); i++) {
        int tempRowData[4] = {-1, -1, -1, -1};

        std::stringstream rowData(content[i]);
        for (int j = 0; j < 4; j++) {
            if (rowData.good())
                rowData >> tempRowData[j];
        }

        // if 3rd or 4th is not set, it means that the row is year data
        if (tempRowData[2] == -1 || tempRowData[3] == -1) {
            decreaseAllFields(fieldArea, fieldSize);
        } else {
            // process the data to field

            int initialCoordinate[2] = {tempRowData[0], tempRowData[1]};
            int finalCoordinate[2] = {tempRowData[2], tempRowData[3]};

            processTheField(fieldArea, initialCoordinate, finalCoordinate);
        }
    }

    // decrease once again to get the final result
    decreaseAllFields(fieldArea, fieldSize);

    // print the field
    printFiled(fieldArea, fieldSize);

    return 0;
}
