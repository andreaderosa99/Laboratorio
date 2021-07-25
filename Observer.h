//
// Created by Andrea on 23/07/21.
//

#ifndef LABORATORIO_OBSERVER_H
#define LABORATORIO_OBSERVER_H

class Observer {
public:
    virtual ~Observer() = default;
    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual void update() = 0;
};


#endif //LABORATORIO_OBSERVER_H
