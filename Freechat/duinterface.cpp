#include <QWidget>
#include "duinterface.h"

Duinterface::Duinterface(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    connect(button, SIGNAL(UserSelect()()),
            this, SLOT(UserSelect()()));
}
