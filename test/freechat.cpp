#include "freechat.h"
#include "ui_freechat.h"

Freechat::Freechat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Freechat)
{
    ui->setupUi(this);
}

Freechat::~Freechat()
{
    delete ui;
}

