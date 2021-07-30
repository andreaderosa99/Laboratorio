//
// Created by Andrea on 30/07/21.
//

#include "testObserver.h"

testObserver::testObserver(FileLoader *s) : subject(s) {
    attach();
}

testObserver::~testObserver() {
    detach();
}

void testObserver::attach() {
    subject->addObserver(this);
}

void testObserver::detach() {
    subject->removeObserver(this);
}
void testObserver::startLoadingFiles() {
    subject->loadFiles();
}

void testObserver::update() {
    string fileName = subject->getFileName().toUtf8().constData();

    if(subject->isLoaded()){
        if(subject->getNumFiles()>0){
            cout<<"Il file: " + fileName + " è stato caricato, ne rimangono da caricare: "<<subject->getNumFiles()<<endl;
        }
        else cout<<"Caricamento completato "<<endl;
    }
    else throw runtime_error("Non ci sono file da caricare");

}