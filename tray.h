#ifndef tray_H
#define tray_H

#include <QtCore/QObject>

class tray : public QObject
{
Q_OBJECT
public:
    tray();
    virtual ~tray();
};

#endif // tray_H
