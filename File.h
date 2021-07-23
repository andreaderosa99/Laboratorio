//
// Created by Andrea on 23/07/21.
//

#ifndef LABORATORIO_FILE_H
#define LABORATORIO_FILE_H
#include <iostream>
#include <stdexcept>
using namespace std;

class File {
public:
    File(const char* fileName);
    ~File();


private:
    FILE* file;
};


#endif //LABORATORIO_FILE_H
