/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#include "Network/connectionf2f.h"
#include "Bin/freechat.h"
#include "Bin/bin.h"

ConnectionF2F::ConnectionF2F(QObject *parent)
    : QTcpSocket(parent)
{

}

void ConnectionF2F::WriteIpAddressOfPeer()
{
    auto list = QHostInfo::fromName(QHostInfo::localHostName()).addresses();

    #ifndef Q_DEBUG
    qDebug() << "Addresses: " << list << endl;
    #endif

    return;
}

void ConnectionF2F::OpenConnectingToPortPeer()
{

    return;
}

void ConnectionF2F::OpenDisconnectingFromPortPeer()
{

    return;
}
