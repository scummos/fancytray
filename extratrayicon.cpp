#include "extratrayicon.h"

ExtraTrayIcon::ExtraTrayIcon(const QIcon& icon, Window x11_window, Display* x11_display, int pid, QObject* parent)
    : QSystemTrayIcon(icon, parent)
    , x11_window(x11_window)
    , x11_display(x11_display)
    , state(VisibleState)
{
    connect(this, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    connect(&timer, SIGNAL(timeout()), this, SLOT(checkExit()));
    timer.setInterval(5000);
    timer.setSingleShot(false);
    timer.start();
}

void ExtraTrayIcon::checkExit()
{
    // TODO this is not good.
    if ( ! QFile::exists("/proc/" + QString::number(pid)) ) {
        exit();
    }
}

ExtraTrayIcon::~ExtraTrayIcon()
{

}

void ExtraTrayIcon::exit()
{
    QApplication::quit();
}

void ExtraTrayIcon::exiting()
{
    qDebug() << "exiting";
    XMapWindow(x11_display, x11_window);
    XFlush(x11_display);
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