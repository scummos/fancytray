#include <QCoreApplication>
#include "tray.h"


int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    tray foo;
    return app.exec();
}
