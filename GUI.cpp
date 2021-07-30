//
// Created by Andrea on 23/07/21.
//

#include "GUI.h"

GUI::GUI(FileLoader *s) : subject(s) {

    attach();

    //Dimensioni finestra
    setFixedSize(800, 400);
    setWindowTitle("File Loader");

    //Bottone
    button = new QPushButton("Carica", this);
    button->setGeometry(300,150,200,30);

    //ProgressBar
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(100,190,600,30);

    progressBar -> setRange(0,100);
    progressBar->setValue(0);


    label = new QLabel(this);
    label->setAlignment(Qt::AlignCenter);

    errorMessage = new QErrorMessage(this);

    messageBox = new QMessageBox(this);


    description = new QLabel("Clicca su carica per iniziare a caricare i files",this);
    description->setGeometry(250,90,300,30);

    description->setAlignment(Qt::AlignCenter);

    connect(button, SIGNAL(released()), this, SLOT(startLoadingFiles()));

}

void GUI::startLoadingFiles() {
    try {
        subject->loadFiles();
        progressBar->setValue(100);
    } catch(runtime_error& e){
        cout << e.what() << endl;
    }
}

GUI::~GUI() {
    detach();
}

void GUI::attach() {
    subject -> addObserver(this);
}

void GUI::detach() {
    subject -> removeObserver(this);
}

void GUI::update() {

        if(subject->isLoaded()){
            label->setGeometry(310,230,200,100);

            QString remainingFiles = QString::number(subject->getNumFiles());

            label->setText(label->text() + subject->getFileName() + " caricato\n");
            progressBar->setValue(ceil(progressBar->value() + (((1.0 / (subject->getNumFiles()+1))) * 100)));

            this_thread::sleep_for(chrono::seconds(1));

            //Aggiunto messaggio che dice quanti file rimangono da caricare
            messageBox->setText("E' stato aggiunto un file");
            messageBox->setInformativeText("Rimangono ancora "+ remainingFiles + " files da caricare");
            if(subject->getNumFiles()==0)
                messageBox->setInformativeText("Caricamento completato ");

            messageBox->exec();
        }

       else errorMessage -> showMessage("Non è stato caricato nessun file");

}