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
    parseFile(std::string path);

private:
    void getContent();
    void setCount();
};


#endif //FINALPROJECT_PARSEFILE_H
