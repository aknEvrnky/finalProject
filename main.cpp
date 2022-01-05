#include "field.h"

int main() {

    // get file directory
    std::string fileDirectory = "../fieldInfo1.txt";

    // parse the file
    parseFile parsedFile(fileDirectory);

    // create the field object from the parsed file
    field tirednessField(&parsedFile);

    // render the map
    tirednessField.renderMap();

    return 0;
}
