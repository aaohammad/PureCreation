#include <QtGui/QApplication>
#include "main-gui.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainGUI mainGUI;
    mainGUI.showMaximized ();
    return app.exec();
}
