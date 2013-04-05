#ifndef trayTEST_H
#define trayTEST_H

#include <QtCore/QObject>

class trayTest : public QObject
{
Q_OBJECT
private slots:
    void initTestCase();
    void init();
    void cleanup();
    void cleanupTestCase();

    void someTest();
};

#endif // trayTEST_H
