//
// Created by Andrea on 23/07/21.
//

#ifndef LABORATORIO_SUBJECT_H
#define LABORATORIO_SUBJECT_H


#include "Observer.h"

class Subject{
public:
    virtual ~Subject() = default;
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notify() = 0;
};


#endif //LABORATORIO_SUBJECT_H
