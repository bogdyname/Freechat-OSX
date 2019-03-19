/*
***Copyright (C) 2019 Freechat Inc
***Contact: bogdyname@gmail.com
*/

#include "freechat.h"
#include "ui_freechat.h"

freechat::freechat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::freechat)
{
    ui->setupUi(this);
}

freechat::~freechat()
{
    delete ui;
}
