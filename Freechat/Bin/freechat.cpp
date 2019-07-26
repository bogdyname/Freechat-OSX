/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#include "Bin/freechat.h"
#include "Network/connectionf2f.h"
#include <QtWidgets>

Freechat::Freechat(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    lineForTypeText->setFocusPolicy(StrongFocus);
    textFieldForViewMessages->setFocusPolicy(NoFocus);
    textFieldForViewMessages->setReadOnly(true);
    listWithIpOfUsers->setFocusPolicy(NoFocus);

    connect(&on_showNetworkInfo_clicked, SIGNAL(), SLOT());
    connect(&on_showNetworkSettings_clicked, SIGNAL(), SLOT());
}

void Freechat::on_showNetworkSettings_clicked(bool checked)
{
        QString text = QInputDialog::getText(this, tr("Network settings"),
        tr("Write IP address of peer:"),
        QLineEdit::Normal, QDir::home().dirName(), &checked);

        if (checked && !text.isEmpty())
        {
            writeIpOfPeer.setText(text);
        }
        else
        {
            /*clear code*/
        }

        return;
}

void Freechat::on_showNetworkInfo_clicked(bool checked)
{


    return;
}

void Freechat::on_writeIpOfPeer_textEdited(const QString &arg1)
{

    return;
}

void Freechat::on_writeNickOfPeer_textEdited(const QString &arg1)
{


    return;
}
