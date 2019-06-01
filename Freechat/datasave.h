/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#ifndef DATASAVE_H
#define DATASAVE_H

#include <QStorageInfo>
#include <QTextStream>
#include <QSaveFile>
#include <QIODevice>
#include <QTimer>
#include <QFile>

class Username;

class Datasave : public QFile
{
    Q_OBJECT

public:
    QFile fileWithData;
    QFile fileWithDataForBackup;

    QTimer runTimer;
    QByteArray block;

    QStorageInfo storage = QStorageInfo::root();

public:
    Datasave(QObject *parent = nullptr);

signals:
    void RunTimeIsOver();
    void SaveDataFileAs();
    void CheckYourMemorySize();
    void ReadFileForViewMessages();
    void CheckUsernameForSaveFile();

public slots:
    void DeleteAllDataForFreeMemory();
    void RunBackupFiles();
    void ReadFile();

protected:
    bool CheckForFileExists();
    bool CheckForFileIsOpen();
};

#endif // DATASAVE_H
