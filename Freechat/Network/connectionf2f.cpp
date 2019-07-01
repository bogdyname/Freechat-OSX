/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/
#include "Network/connectionf2f.h"
#include "Bin/bin.h"

ConnectionF2F::ConnectionF2F(QObject *parent)
    : QTcpSocket(parent)
{

}

/////////////////////////////////////////////////////

Peerout::~Peerout()
{
    delete socket;
}

void Peerout::MakeSocket()
{
    GetIpAddressFromWAN(strWANip);
    socket = new QTcpSocket(this);
    socket->connectToHost(strWANip, 80);

        if(socket->waitForConnected(3000))
        {
            qDebug() << "Connected!";

            socket->write("DATA OF TEXT");
            socket->waitForBytesWritten(1000);
            socket->waitForReadyRead(3000);
            qDebug() << "Reading: " << socket->bytesAvailable();

            qDebug() << socket->readAll();

            socket->close();
        }
        else
        {
            qDebug() << "Not connected!";
        }
}

void Peerout::GetIpAddressFromWAN(QString &textWithIPAddres)
{
        QNetworkAccessManager networkManager;
        QHostAddress IP;

        QUrl url("https://api.ipify.org");
        QUrlQuery query;
        query.addQueryItem("format", "json");
        url.setQuery(query);

        QNetworkReply* reply = networkManager.get(QNetworkRequest(url));

        connect(reply, &QNetworkReply::finished, [&]()
        {
            if(reply->error() != QNetworkReply::NoError)
            {
                qDebug() << "error: " << reply->error();
            }
            else
            {
                QJsonObject jsonObject= QJsonDocument::fromJson(reply->readAll()).object();
                QHostAddress ip(jsonObject["ip"].toString());

                IP = ip;
            }
            reply->deleteLater();
        }
        );

        textWithIPAddres = IP.toString();

        return;
}


/////////////////////////////////////////////////////////////////
