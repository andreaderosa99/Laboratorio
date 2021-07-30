//
// Created by Andrea on 23/07/21.
//

#ifndef LABORATORIO_FILELOADER_H
#define LABORATORIO_FILELOADER_H


#include <list>
#include <iostream>
#include <QString>

#include "Subject.h"
#include "File.h"

class FileLoader : public Subject {
public:

    FileLoader() : numFiles(0) {}

    //Modificato, non prende più in ingresso una lista di string
    void loadFiles();

    void addFile(File& file);

    //Aggiunta rimozione file
    void removeFile(File& file);

    int getNumFiles() const;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

    const QString &getFileName() const;

    bool isLoaded() const;


private:
    list<File> fileList; //Ora c'è una lista di File e non di string
    list<Observer*> observers;
    bool is_Loaded;
    int numFiles;
    QString fileName;
};


#endif //LABORATORIO_FILELOADER_H
