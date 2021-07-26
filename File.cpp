//
// Created by Andrea on 23/07/21.
//

#include "File.h"
using namespace std;

File::File(const char* fileName) {
    file = fopen(fileName, "r");
    if(!file)
        throw runtime_error("Non è possibile aprire il file " + string(fileName));

}

File::~File() {
    int control = fclose(file);
    if(control){
        throw runtime_error("Non è possibile chiudere il file ");
    }
}