#include "freechat.h"
#include "peerin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Freechat w;
    w.show();

    Peerin testServer; // CONNECTING WORK!

    return a.exec();
}
