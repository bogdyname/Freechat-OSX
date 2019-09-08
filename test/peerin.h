#ifndef PEERIN_H
#define PEERIN_H

#include <QTcpServer>
#include <QNetworkInterface>
#include <QAbstractSocket>
#include <QNetworkSession>
#include <QHostAddress>
#include <QHostAddress>
#include <QTimerEvent>
#include <QTcpSocket>
#include <QHostInfo>
#include <QtNetwork>

class Peerin : public QTcpServer
{
    Q_OBJECT

public:
    explicit Peerin(QObject *parent = nullptr);

    void incomingConnection(qintptr socketDescriptor);

signals:

public slots:
    void ReadData();
    void Disconnecting();

private:
    QTcpServer *server;
};
#endif
