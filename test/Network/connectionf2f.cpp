/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#include "Network/connectionf2f.h"

<<<<<<< HEAD
extern QString yourIp;
=======
static QString globalNetworkBuffer;
>>>>>>> master

ConnectionF2F::ConnectionF2F(QObject *parent)
    : QTcpSocket(parent)
{
<<<<<<< HEAD
    /*now is empty*/
=======

>>>>>>> master
}

ConnectionF2F::~ConnectionF2F()
{

}

void ConnectionF2F::NetworkInfo()
{
       QString localhostname =  QHostInfo::localHostName();
       QString localhostIP;
       QList<QHostAddress> hostList = QHostInfo::fromName(localhostname).addresses();

       foreach (const QHostAddress& address, hostList)
       {
           if (address.protocol() == QAbstractSocket::IPv4Protocol && address.isLoopback() == false)
           {
                localhostIP = address.toString();
           }
           else
           {
               /*clear code*/
           }
       }

       QString localMacAddress;
       QString localNetmask;

       foreach (const QNetworkInterface& networkInterface, QNetworkInterface::allInterfaces())
       {
           foreach (const QNetworkAddressEntry& entry, networkInterface.addressEntries())
           {
               if (entry.ip().toString() == localhostIP)
               {
                   localMacAddress = networkInterface.hardwareAddress();
                   localNetmask = entry.netmask().toString();
                   break;
               }
               else
               {
                   /*clear code*/
               }
           }
       }

       #ifndef Q_DEBUG
       qDebug() << "Localhost name: " << localhostname;
       qDebug() << "IP = " << localhostIP;
       qDebug() << "MAC = " << localMacAddress;
       qDebug() << "Netmask = " << localNetmask;
       #endif

<<<<<<< HEAD
       Freechat::yourIp += localhostIP;
=======
       globalNetworkBuffer += localhostIP;
}

void ConnectionF2F::WriteIpAddressFromPeer()
{
    ip += globalNetworkBuffer;
    globalNetworkBuffer.clear();

    return;
>>>>>>> master
}
