//
// Created by Andrea on 23/07/21.
//

#ifndef LABORATORIO_FILELOADER_H
#define LABORATORIO_FILELOADER_H


#include <list>
#include <iostream>

#include "Subject.h"
#include "File.h"

class FileLoader : public Subject {
public:

    FileLoader() : numFiles(0) {}

    void loadFiles(list<string> &fileNames);
    void handleFile(string fileName);

    bool isLoaded() const;

    int getNumFiles() const;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

private:
    list<Observer*> observers;
    int numFiles;
    bool is_Loaded;
};


#endif //LABORATORIO_FILELOADER_H