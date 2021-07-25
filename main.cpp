#include <QApplication>
#include "FileLoader.h"
#include "GUI.h"


int main(int argc, char *argv[]) {

    QApplication app(argc,argv);
    FileLoader fileLoader;
    GUI window(&fileLoader);
    window.show();
    return app.exec();
}