#ifndef FREECHAT_H
#define FREECHAT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Freechat; }
QT_END_NAMESPACE

class Freechat : public QMainWindow
{
    Q_OBJECT

public:
    Freechat(QWidget *parent = nullptr);
    ~Freechat();

private:
    Ui::Freechat *ui;
};
#endif // FREECHAT_H
