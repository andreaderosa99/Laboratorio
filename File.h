//
// Created by Andrea on 23/07/21.
//

#ifndef LABORATORIO_FILE_H
#define LABORATORIO_FILE_H
#include <iostream>
using namespace std;

class File {
public:

    //un file ora è formato da nome,estensione e dimensione
    File(const string &name, const string &extension, int dimension);

    ~File();

    const string &getName() const;

    const string &getExtension() const;

    bool operator==(const File &right) const;

private:
    string name,extension;
    int dimension;
};


#endif //LABORATORIO_FILE_H
