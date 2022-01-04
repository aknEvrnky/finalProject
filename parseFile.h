//
// Created by evren on 4.01.2022.
//

#ifndef FINALPROJECT_PARSEFILE_H
#define FINALPROJECT_PARSEFILE_H
#include <iostream>

class parseFile {
public:
    int rowCount = 0;
    std::string content[1000];
    std::string filePath;
    int fieldSize[2];
    parseFile(std::string path);

private:
    void setContent();
    void setCount();
    void setFieldSize();
};


#endif //FINALPROJECT_PARSEFILE_H
