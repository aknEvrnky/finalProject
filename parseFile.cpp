//
// Created by evren on 4.01.2022.
//

#include <fstream>
#include <sstream>
#include "parseFile.h"

parseFile::parseFile(std::string filePath) {
    this->filePath = filePath;
    this->setCount();
    this->setContent();
    this->setFieldSize();
}

void parseFile::setCount() {
    std::ifstream file(this->filePath);
    std::string tempRow;
    while (std::getline(file, tempRow)) {
        this->rowCount++;
    }
    file.close();
}

void parseFile::setContent() {
    std::ifstream file(this->filePath);
    std::string tempRow;
    int i = 0;
    while (std::getline(file, tempRow)) {
        this->content[i] += tempRow + "\n";
        i++;
    }
    file.close();
}

void parseFile::setFieldSize() {
    std::stringstream stream(this->content[0]);
    int i = 0;
    while (stream.good() && i < 2){
        stream >> this->fieldSize[i];
        i++;
    }
}
