/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#include <QtNetwork/QNetworkInterface>
#include <QtCore/QCoreApplication>
#include <QAbstractSocket>
#include <QHostAddress>
#include <QJsonObject>
#include <QTextStream>
#include <QDataStream>
#include <QByteArray>
#include <QIODevice>
#include <QHostInfo>
#include <QSaveFile>
#include <QDateTime>
#include <QtNetwork>
#include <QString>
#include <QFile>

#ifndef USERNAME_H
#define USERNAME_H

class Freechat;
class ConnectionF2F;

class Username : public QFile
{
    Q_OBJECT

public:
    Username(QObject *parent = nullptr);
    ~Username();

private slots:
    inline void ReadingIpAddress(QFile &fileWithIP);
    inline void ReadingMACAddress(QFile &fileWithMac);
    void TranslationName(QFile &fileWithMAC, QString &translator);
};

#endif // USERNAME_H

#ifndef USERNAMETABLE_H
#define USERNAMETABLE_H

class Usernametable : public Username
{
    Q_OBJECT

public:
    Usernametable(QObject *parent = nullptr);
    ~Usernametable();

protected:
    inline void MakeFileWithIp();
    inline void MakeFileWithMac();
    void GetIpAddressFromWAN(QString &textWithIPAddres);
    inline void GetMacAddress(QString &textWithMacAddresOfUser);
};


#endif // USERNAMETABLE_H
