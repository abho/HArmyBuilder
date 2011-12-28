#include <QtGui/QApplication>
#include "harmybuilder.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HArmyBuilder w;
    w.show();

    return a.exec();
}
