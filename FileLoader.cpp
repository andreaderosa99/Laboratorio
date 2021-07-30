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

void FileLoader::loadFiles() {

    if(fileList.empty()){
        is_Loaded=false;
        notify();
        throw runtime_error("Nessun file da caricare");
    }
    else
        is_Loaded=true;

    for (auto file_Name : fileList){
        this->fileName = QString::fromStdString(file_Name.getName()+"."+file_Name.getExtension());
        notify();
        fileList.pop_front();
    }
}

void FileLoader::addFile(const File& file) {
    fileList.push_back(file);
}

void FileLoader::removeFile(const File& file){

        if(!fileList.empty()){
            auto it = find(fileList.begin(),fileList.end(),file);
            fileList.remove(file);
        }
        else throw runtime_error("Non ci sono file che possono essere eliminati");
}


const QString &FileLoader::getFileName() const {
    return fileName;
}

bool FileLoader::isLoaded() const {
    return is_Loaded;
}

int FileLoader::getNumFiles() const {
    return fileList.size();
}


