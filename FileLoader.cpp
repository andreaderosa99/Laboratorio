//
// Created by Andrea on 23/07/21.
//

#include "FileLoader.h"

void FileLoader::addObserver(Observer *o) {
    observers.push_back(o);
}

void FileLoader::removeObserver(Observer *o) {
    observers.remove(o);
}

void FileLoader::notify() {
    for(auto observer : observers)
        observer->update();
}

void FileLoader::loadFiles(list<string> &fileNames) {
    numFiles = fileNames.size();
    if (numFiles == 0){
        throw runtime_error("Non ci sono files");
    }
    else {
        for (auto fileName : fileNames)
            handleFile(fileName);
    }


}

void FileLoader::handleFile(string fileName) {
    this->fileName = QString::fromStdString(fileName);

    try {
        File file(fileName.c_str());
        is_Loaded = true;
        notify();
    }
    catch (runtime_error& e){
        cerr << e.what() << endl;
        is_Loaded = false;
        notify();
    }
}

int FileLoader::getNumFiles() const {
    return numFiles;
}

bool FileLoader::isLoaded() const {
    return is_Loaded;
}

const QString &FileLoader::getFileName() const {
    return fileName;
}