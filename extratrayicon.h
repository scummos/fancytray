#ifndef tray_H
#define tray_H

#include <QtCore/QObject>
#include <QSystemTrayIcon>
#include <QDebug>

#include <X11/Xlib.h>
#include <X11/X.h>

class ExtraTrayIcon : public QSystemTrayIcon
{
Q_OBJECT
public:
    enum State {
        VisibleState,
        InvisibleState
    };
    ExtraTrayIcon(const QIcon& icon, Window x11_window, Display* x11_display, QObject* parent = 0);
    virtual ~ExtraTrayIcon();
public slots:
    void iconActivated(QSystemTrayIcon::ActivationReason);
private:
    Window x11_window;
    Display* x11_display;
    State state;
};

#endif // tray_H
