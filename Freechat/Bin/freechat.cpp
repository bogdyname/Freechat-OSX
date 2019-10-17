/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#include "Bin/bin.h"
#include "Bin/freechat.h"
#include "Network/connectionf2f.h"

Freechat::Freechat(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::Freechat)
{
    ui->setupUi(this);

    ui->lineForTypeText->setFocusPolicy(StrongFocus);
    ui->textFieldForViewMessages->setFocusPolicy(NoFocus);
    ui->textFieldForViewMessages->setReadOnly(true);
    ui->listWithNickName->setFocusPolicy(NoFocus);

}

Freechat::~Freechat()
{
    delete ui;
}

void Freechat::on_showNetworkInfo_clicked(bool checked)
{
    switch(checked)
    {
    case true:
        QMessageBox::information(this, tr("Network Info"),
                                 tr("Your LAN IP address: "), yourIp);
        yourIp.clear();
        break;
    case false:
        break;
    }

    return;
}

void Freechat::on_connectionToPeer_clicked(bool checked)
{
    bool reply = false;

    switch(checked)
    {
    case true:
    {
        QMessageBox::information(this, tr("Connection"),
                                 tr("Connecting to peer..."));

        AskForConnectingToPortPeer();

        if(ReplyFromPortPeer(reply) == true)
        {

        }
        else
        {
            QMessageBox::information(this, tr("Disconnected"),
                                     tr("Peer does not want to connect with you"));
        }
    }
        break;
    case false:
        break;
    }

    return;
}

void Freechat::AskForConnectingToPortPeer()
{

    return;
}

void Freechat::AskForDisconnectingFromPortPeer()
{

    return;
}

bool Freechat::ReplyFromPortPeer(bool &reply)
{
    if(reply == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Freechat::SetTextInsideFiledOfChat()
{

    return;
}

void Freechat::on_writeNickOfPeer_textChanged()
{

    return;
}
void Freechat::on_writeLanIpOfPeer_textChanged()
{

    return;
}

void Freechat::on_writeWanIpOfPeer_textChanged()
{


    return;
}

void Freechat::on_wanButton_clicked(bool checked)
{

    switch(checked)
    {
    case true:
        wanIpOfPeer = ui->writeWanIpOfPeer->text();
        globalBuffer += wanIpOfPeer;
        ConnectionF2F::globalNetworkBuffer += globalBuffer;
        wanIpOfPeer.clear();
        globalBuffer.clear();
        break;
    case false:
        break;
    }

    return;
}

void Freechat::on_lanButton_clicked(bool checked)
{
    switch(checked)
    {
    case true:
        lanIpOfPeer = ui->writeLanIpOfPeer->text();
        globalBuffer += lanIpOfPeer;
        ConnectionF2F::globalNetworkBuffer += globalBuffer;
        lanIpOfPeer.clear();
        globalBuffer.clear();
        break;
    case false:
        break;
    }

    return;
}

void Freechat::on_nickButton_clicked(bool checked)
{
    switch(checked)
    {
    case true:
        nickNameOfPeer = ui->writeNickOfPeer->text();
        globalBuffer += nickNameOfPeer;
        ConnectionF2F::globalNetworkBuffer += globalBuffer;
        nickNameOfPeer.clear();
        globalBuffer.clear();
        break;
    case false:
        break;
    }

    return;
}

void Freechat::on_listWithNickName_itemDoubleClicked(QListWidgetItem *item)
{
    connect(textFieldForViewMessages, SIGNAL(SetTextInsideFiledOfChat()), this, SLOT(paste()));

    // need to add elements from nick list into *item QListWidgetItem for show nicknames
    // not done
    QListWidgetItem *item = new QListWidgetItem(listWithNickName->toPlainText());

    ui->listWithNickName->addItem(item);

    //write here double ckicked on nick and copy data from file and past it in chat field

    return;
}

void Freechat::on_lineForTypeText_textEdited(QString &messages)
{
    connect(lineForTypeText, SIGNAL(inputRejected()), this, SLOT(PassMessagesInsideBuffer()));

    messages = ui->lineForTypeText->text(); //pass text from line for type
    bufferOfMessages += messages;//write inside buffer

    return;
}

void Freechat::PassMessagesInsideBuffer()
{
    globalBuffer += bufferOfMessages; // pass messages to global buffer for save in file
    ConnectionF2F::globalNetworkBuffer += globalBuffer;

    globalBuffer.clear();

    return;
}
