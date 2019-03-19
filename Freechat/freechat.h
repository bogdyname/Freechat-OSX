/*
***Copyright (C) 2019 Freechat Inc
***Contact: bogdyname@gmail.com
*/

#ifndef FREECHAT_H
#define FREECHAT_H

#include <QMainWindow>

namespace Ui {
class freechat;
}

class freechat : public QMainWindow
{
    Q_OBJECT

public:
    explicit freechat(QWidget *parent = nullptr);
    ~freechat();

private:
    Ui::freechat *ui;
};

#endif // FREECHAT_H
