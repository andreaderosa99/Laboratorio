#include <QApplication>
#include "FileLoader.h"
#include "GUI.h"


int main(int argc, char *argv[]) {

    QApplication app(argc,argv);

    File file("Document","doc",520);
    File file2("Note","txt",100);
    File file3("Document2","xlsx",837);
    File file4("Image","jpg",1543);

    FileLoader fileLoader;
    fileLoader.addFile(file);
    fileLoader.addFile(file2);
    fileLoader.addFile(file3);
    fileLoader.addFile(file4);

    try {
        fileLoader.removeFile(file2);
    }
    catch (runtime_error& e) {
        cout << e.what()<< endl;
    }

    GUI window(&fileLoader);
    window.show();
    return app.exec();
}