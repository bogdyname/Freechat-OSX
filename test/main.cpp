#include "Bin/freechat.h"
#include "Network/connectionf2f.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // network
    ConnectionF2F networkTest;
    networkTest.NetworkInfo();

<<<<<<< HEAD
=======
    Peerout peer("192.168.1.27");
    Peerin server(3366);

>>>>>>> master
    // ui
    Freechat window;
    window.show();

    return a.exec();
}
