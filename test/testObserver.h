//
// Created by Andrea on 30/07/21.
//

#ifndef MAIN_CPP_TESTOBSERVER_H
#define MAIN_CPP_TESTOBSERVER_H

#include "../FileLoader.h"
#include "../Observer.h"

#include "gtest/gtest.h"

class testObserver : public Observer{
public:
    explicit testObserver(FileLoader* s);
    virtual ~testObserver();

    void attach() override;
    void detach() override;
    void update() override;

    void startLoadingFiles();

private:
    FileLoader* subject;
};


#endif //MAIN_CPP_TESTOBSERVER_H
