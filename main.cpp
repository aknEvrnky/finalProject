#include <iostream>
#include "parseFile.h"
#include "field.h"


int main() {

    // get file directory from user
    std::string fileDirectory = "C:\\Users\\evren\\Desktop\\finalProject\\fieldInfo1.txt";

    // read the file
    parseFile parsedFile(fileDirectory);

    // create the field
    field fieldArea(&parsedFile);

    // render the map
    fieldArea.renderMap();

    return 0;
}
