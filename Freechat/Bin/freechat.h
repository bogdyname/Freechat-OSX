/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#include "Bin/bin.h"
#include "ui_freechat.h"
#include <QTextTableFormat>
#include <QDialog>

#ifndef FREECHAT_H
#define FREECHAT_H
class Freechat : public QDialog, private Ui::Freechat
{
    Q_OBJECT

public:
    Freechat(QWidget *parent = nullptr);
};
#endif
