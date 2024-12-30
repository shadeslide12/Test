#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QCoreApplication::setOrganizationName("DockDemo");
    QCoreApplication::setApplicationName("DockLayout");
    
    MainWindow window;
    window.show();
    
    return app.exec();
}