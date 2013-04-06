#include <QApplication>
#include <QDebug>
#include <iostream>

#include <X11/Xlib.h>
#include <unistd.h>

#include <QSystemTrayIcon>

#include "extratrayicon.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    bool ok = false;
    unsigned int searchpid = -1;
    if ( argc == 2 ) {
        searchpid = QString(argv[1]).toInt(&ok);
    }
    if ( ! ok ) {
        std::cerr << "Usage: tray <process id>" << std::endl;
    }

    Display *d = XOpenDisplay(0);
    Window found = -1;
    if ( d ) {
        Atom atom = XInternAtom(d, "_NET_CLIENT_LIST", True);
        XFlush(d);
        Atom actual_type;
        int actual_format;
        int max_len = 10000;
        unsigned long nitems;
        unsigned long bytes_after;
        unsigned char *prop;
        int status = XGetWindowProperty(d, DefaultRootWindow(d), atom, 0, (max_len+3)/4,
                                        False, AnyPropertyType, &actual_type, &actual_format, &nitems,
                                        &bytes_after, &prop);
        for (int i = 0; i < nitems; i++) {
            int id = ((quint32*) prop)[i];
            if ( ! id ) {
                continue;
            }
            atom = XInternAtom(d, "_NET_WM_PID", True);
            XFlush(d);
            unsigned char* pid;
            unsigned long pidcount;
            int status = XGetWindowProperty(d, (Window) id, atom, 0, (max_len+3)/4,
                                            False, AnyPropertyType, &actual_type, &actual_format, &pidcount,
                                            &bytes_after, &pid);
            if ( status < Success || pid == 0 ) {
                continue;
            }
            if ( *(unsigned int*)(pid) == searchpid ) {
                found = (Window) id;
                qDebug() << "found window:" << id;
                break;
            }
        }
    }
    if ( found != -1 ) {
        ExtraTrayIcon icon(QIcon("/usr/share/icons/terminology.png"), found, d);
        icon.show();
        return app.exec();
    }
    else {
        std::cerr << "Sorry, could not find a window for process " << searchpid << "." << std::endl;
    }
}
