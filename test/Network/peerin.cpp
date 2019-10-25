/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#include "peerin.h"

Peerin::Peerin(QObject *parent)
    : QTcpServer(parent)
{
    server = new QTcpServer(this);
    server->setMaxPendingConnections(1);

    connect(server, SIGNAL(newConnection()), this, SLOT(SlotNewConnection()));

        if(listen(QHostAddress::Any, 80))
        {
           #ifndef Q_DEBUG
           qDebug() << "Server: started";
           #endif
        }
        else
        {
            #ifndef Q_DEBUG
            qDebug() << "Server: not started: " << server->errorString();
            #endif

            server->close();
        }
}

Peerin::~Peerin()
{
    if(server != nullptr)
    {
        delete server;
    }
    else
    {
        /*clear code*/
    }

    return;
}

void Peerin::SlotNewConnection()
{
    clientSocket1 = server->nextPendingConnection();

    connect(clientSocket1, SIGNAL(disconnect()), clientSocket1, SLOT(deleteLater()));
    connect(clientSocket1, SIGNAL(readyRead()), this, SLOT(SlotReadClient()));

    Freechat::viewField = "Connected";
    SendResponseToClient(clientSocket1, Freechat::viewField);

    return;
}

void Peerin::SlotReadClient()
{
    clientSocket2 = (QTcpSocket*)sender();
    QDataStream in(clientSocket2);

    in.setVersion(QDataStream::Qt_5_12);

    for(;;)
    {
        if(!nextBlockSize)
        {
            if((clientSocket2->bytesAvailable()) < (sizeof (quint16)))
            {
                break;
            }
            else
            {
                /*clear code*/
            }

            in >> nextBlockSize;
        }
        else
        {
            /*clear code*/
        }

        if((clientSocket2->bytesAvailable()) < nextBlockSize)
        {
            break;
        }
        else
        {
            /*clear code*/
        }

        QTime time = QTime::currentTime();
        QString strOfTime;
        in >> time >> strOfTime;

        QString strMessage = "Respons from peer:" + time.toString() + ": " + Freechat::bufferOfMessages + "\n";

        Freechat::viewField = strMessage;
        nextBlockSize = 0;
    }

    return;
}

void Peerin::SendResponseToClient(QTcpSocket *socket, QString &messages)
{
    QByteArray block;

    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out << quint16(0) << QTime::currentTime() << messages;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof (quint16));

    socket->write(block);
    socket->flush();

    messages.clear();

    return;
}

void Peerin::SendToClientFlush()
{
    SendResponseToClient(clientSocket2, Freechat::bufferOfMessages);
    Freechat::bufferOfMessages.clear();

    return;
}
