#include "Timbiriche.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Timbiriche w;
    w.show();

    return a.exec();
}
