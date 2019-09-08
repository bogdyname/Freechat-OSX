#include "peerin.h"

Peerin::Peerin(QObject *parent)
    : QTcpServer(parent)
{
    server = new QTcpServer(this);

    if(listen(QHostAddress::Any, 80))
    {
       #ifndef Q_DEBUG
       qDebug() << "Server: started";
       #endif
    }
    else
    {
        #ifndef Q_DEBUG
        qDebug() << "Server: not started: " << errorString();
        #endif
    }
}

void Peerin::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()), this, SLOT(ReadData()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(Disconnecting()));

    return;
}

void Peerin::ReadData()
{

    return;
}

void Peerin::Disconnecting()
{

    return;
}
