#include "extratrayicon.h"

ExtraTrayIcon::ExtraTrayIcon(const QIcon& icon, Window x11_window, Display* x11_display, QObject* parent)
    : QSystemTrayIcon(icon, parent)
    , x11_window(x11_window)
    , x11_display(x11_display)
    , state(VisibleState)
{
    connect(this, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

ExtraTrayIcon::~ExtraTrayIcon()
{

}

void ExtraTrayIcon::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    qDebug() << "icon activated";
    if ( state == VisibleState ) {
        XUnmapWindow(x11_display, x11_window);
        state = InvisibleState;
    }
    else {
        XMapWindow(x11_display, x11_window);
        state = VisibleState;
    }
    XFlush(x11_display);
}

#include "extratrayicon.moc"