//
// Created by Andrea on 23/07/21.
//

#ifndef LABORATORIO_GUI_H
#define LABORATORIO_GUI_H

#include <QMainWindow>
#include <QPushButton>
#include <QProgressBar>
#include <QString>
#include <QLabel>
#include <QErrorMessage>
#include <QFrame>
#include <cmath>
#include "Observer.h"
#include "FileLoader.h"

class GUI : public QMainWindow, public Observer {
Q_OBJECT
public:
    explicit GUI(FileLoader* s);

    virtual ~GUI();

    void attach() override;
    void detach() override;
    void update() override;

public slots:
    void startLoadingFiles();

private:
    FileLoader* subject;
    QPushButton* button;
    QProgressBar* progressBar;
    QLabel* label;
    QErrorMessage* errorMessage;
    QLabel* description;
};





#endif //LABORATORIO_GUI_H
