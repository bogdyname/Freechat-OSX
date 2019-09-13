/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#include "peerout.h"

Peerout::Peerout()
{
    socketlan = new QTcpSocket(this);
    socketwan = new QTcpSocket(this);

    #ifndef Q_DEBUG
    qDebug() << "A new LAN socket created.";
    qDebug() << "A new WAN socket created.";
    #endif

    connect(socketlan, SIGNAL(connected()), this, SLOT(Connected()));
    connect(socketlan, SIGNAL(disconnected()), this, SLOT(Disconnected()));
    connect(socketlan, SIGNAL(readyRead()), this, SLOT(ReadyRead()));
    connect(socketlan, SIGNAL(bytesWritten(qint64)), this, SLOT(BytesWrittenOfData(qint64)));

    connect(socketwan, SIGNAL(connected()), this, SLOT(Connected()));
    connect(socketwan, SIGNAL(disconnected()), this, SLOT(Disconnected()));
    connect(socketwan, SIGNAL(readyRead()), this, SLOT(ReadyRead()));
    connect(socketwan, SIGNAL(bytesWritten(qint64)), this, SLOT(BytesWrittenOfData(qint64)));
}

Peerout::~Peerout()
{
    if((socketlan != nullptr) && (socketwan != nullptr))
    {
        delete socketlan;
        delete socketwan;
    }
    else
    {
        /*clear code*/
    }
}

void Peerout::DoConnect()
{
    socketwan->connectToHost("92.243.182.174", 80);

    if((socketlan->waitForConnected(10000))
        && (socketwan->state() == QTcpSocket::ConnectedState)
            && socketwan->waitForConnected())
    {
        Connected();
        socketlan->connectToHost("192.168.1.15", 80);

        if((socketwan->state() == QTcpSocket::ConnectedState)
           && (socketlan->state() == QTcpSocket::ConnectedState)
                && (socketlan->waitForConnected(3000)))
        {
            Connected();

            socketlan->write("DATA OF TEXT");
            socketlan->flush();
            socketlan->waitForBytesWritten(1000);
            socketlan->waitForReadyRead(3000);
            #ifndef Q_DEBUG
            qDebug() << "Reading: " << socketlan->bytesAvailable();
            qDebug() << socketlan->readAll();
            #endif

            socketlan->close();
        }
        else
        {
            #ifndef Q_DEBUG
            qDebug() << "Not connected!";
            #endif
        }
    }
    else
    {
        #ifndef Q_DEBUG
        qDebug() << "Not connected!";
        #endif
    }

        return;
}

void Peerout::BytesWrittenOfData(qint64 &bytes)
{
    #ifndef Q_DEBUG
    qDebug() << bytes << " bytes written...";
    #endif

    return;
}

void Peerout::Connected()
{
    #ifndef Q_DEBUG
    qDebug() << "Connected!";
    #endif

    return;
}

void Peerout::Disconnected()
{
    #ifndef Q_DEBUG
    qDebug() << "Disconnected!";
    #endif

    return;
}

void Peerout::ReadyRead()
{
    #ifndef Q_DEBUG
    qDebug() << "reading...";
    qDebug() << socketlan->readAll();
    #endif

    return;
}
