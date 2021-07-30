//
// Created by Andrea on 23/07/21.
//

#include "File.h"
using namespace std;

File::File(const string &name, const string &extension, int dimension) : name(name),extension(extension),dimension(dimension) {}

File::~File() {}

const string &File::getName() const {
    return name;
}

const string &File::getExtension() const {
    return extension;
}

bool File::operator==(const File &right) const {
    if(name==right.name && extension==right.extension && dimension==right.dimension)
        return true;
    else return false;
}