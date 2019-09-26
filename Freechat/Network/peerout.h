/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#ifndef PEEROUT
#define PEEROUT

#include "Network/connectionf2f.h"
#include "Bin/freechat.h"

class Peerout : public ConnectionF2F
{
    Q_OBJECT

public:
    Peerout();
    ~Peerout();

public slots:
    void ReadyRead();
    void DoConnect();
    void Connected();
    void Disconnected();
    void BytesWrittenOfData(qint64 &buffer);

private:
    QTcpSocket *socketlan = nullptr;
    QTcpSocket *socketwan = nullptr;
    QString lanIP;
    QString wanIP;
};
#endif