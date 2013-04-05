#include "trayTest.h"
#include <QtTest/QTest>

void trayTest::initTestCase()
{}

void trayTest::init()
{}

void trayTest::cleanup()
{}

void trayTest::cleanupTestCase()
{}

void trayTest::someTest()
{
    QCOMPARE(1,2);
}


QTEST_MAIN(trayTest)
#include "trayTest.moc"
