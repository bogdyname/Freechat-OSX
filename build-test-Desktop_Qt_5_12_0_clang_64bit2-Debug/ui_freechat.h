/********************************************************************************
** Form generated from reading UI file 'freechat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREECHAT_H
#define UI_FREECHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Freechat
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Freechat)
    {
        if (Freechat->objectName().isEmpty())
            Freechat->setObjectName(QString::fromUtf8("Freechat"));
        Freechat->resize(800, 600);
        centralwidget = new QWidget(Freechat);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Freechat->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Freechat);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Freechat->setMenuBar(menubar);
        statusbar = new QStatusBar(Freechat);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Freechat->setStatusBar(statusbar);

        retranslateUi(Freechat);

        QMetaObject::connectSlotsByName(Freechat);
    } // setupUi

    void retranslateUi(QMainWindow *Freechat)
    {
        Freechat->setWindowTitle(QApplication::translate("Freechat", "Freechat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Freechat: public Ui_Freechat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREECHAT_H
