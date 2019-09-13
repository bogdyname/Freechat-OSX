#include "freechat.h"
#include "peerout.h"
#include "peerin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Freechat w;
    w.show();

    Peerin testServer; // CONNECTING WORK!
    Peerout testConnection;
    testConnection.DoConnect();

    return a.exec();
}
