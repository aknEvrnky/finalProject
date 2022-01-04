//
// Created by evren on 4.01.2022.
//

#include <iostream>
#include <fstream>
#include "parseFile.h"

parseFile::parseFile(std::string filePath) {
    this->filePath = filePath;
    this->setCount();
    this->getContent();
}

void parseFile::setCount() {
    std::ifstream file(this->filePath);
    std::string tempRow;
    while (std::getline(file, tempRow)) {
        this->rowCount++;
    }
    file.close();
}

void parseFile::getContent() {
    std::ifstream file(this->filePath);
    std::string tempRow;
    int i = 0;
    while (std::getline(file, tempRow)) {
        this->content[i] += tempRow + "\n";
        i++;
    }
    file.close();
}