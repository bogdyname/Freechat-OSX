/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#include "Data/datasave.h"

Datasave::Datasave(Freechat *parent)
    : QFile(parent)
{


   QString fname = "filewd" +
           QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss") + ".txt";
   QFile file(fname);

   QString strWithIP;
   PassOnWANIp(strWithIP);

   if(buffer != nullptr)
   {
       buffer = new QByteArray;

       if((file.exists()) && (file.isOpen()))
       {
            if(file.open(WriteOnly))
            {
                QTextStream writeStream(&file);
                writeStream << strWithIP;
                writeStream << /*Data from text field*/;
                file.write(*buffer);
                file.close();
            }
            else
            {
                file.flush();
            }
        }
        else
        {
            file.flush();
        }
   }

   QDir().mkdir(QApplication::applicationDirPath()+"/../savedata");
}

Datasave::Datasave(QFile &fileWithData, QFile &fileWithDataForBackup)
{
    if(buffer != nullptr)
    {
        buffer = new QByteArray;

        if((fileWithData.open(ReadOnly)) && (fileWithDataForBackup.open(WriteOnly)))
        {
            *buffer = fileWithData.readAll();
            fileWithDataForBackup.write(*buffer);
            fileWithData.close();
            fileWithDataForBackup.close();
        }
        else
        {
            fileWithData.flush();
            fileWithDataForBackup.flush();
        }
    }
    else
    {
        fileWithData.flush();
        fileWithDataForBackup.flush();
    }
}

Datasave::~Datasave()
{
    delete buffer;
}

inline bool Datasave::CheckIpAddressForSaveFile(QString &strWithIpOfPeer)
{
    QString str;

    PassOnWANIp(str);
    ReadFirstStringFromDataFile(strWithIpOfPeer);

    if(str == strWithIpOfPeer)
    {
        return true;
    }
    else
    {
        return false;
    }
}

inline QString Datasave::ReadFirstStringFromDataFile(QString &strWithIpOfPeer)
{
    //get first string from data file

    return strWithIpOfPeer;
}

void Datasave::CheckYourMemorySize()
{
    #ifndef Q_DEBUG
    qDebug() << storage.rootPath();
    #endif

    if (storage.isReadOnly())
    {
        #ifndef Q_DEBUG
        qDebug() << "isReadOnly:" << storage.isReadOnly();
        #endif
    }
    else
    {
        /*clear code*/
    }

    #ifndef Q_DEBUG
    qDebug() << "name:" << storage.name();
    qDebug() << "fileSystemType:" << storage.fileSystemType();
    qDebug() << "size:" << storage.bytesTotal()/1000/1000 << "MB";
    qDebug() << "availableSize:" << storage.bytesAvailable()/1000/1000 << "MB";
    #endif

    if (storage.bytesFree() == 1)
    {
        QMessageBox::information(this, tr("WARNING!"),
                        tr("Check your memory size!"));
    }
    else
    {
        /*clear code*/
    }

    return;
}

inline void Datasave::DeleteAllDataForFreeMemory(QFile &fileWithData, QFile &fileWithDataForBackup)
{
    fileWithData.remove();
    fileWithDataForBackup.remove();

    return;
}

void Datasave::ReadFileForViewMessages()
{


    return;
}

inline void Datasave::ReadFile(QFile &fileWithData)
{
    if ((fileWithData.exists()) && (fileWithData.open(ReadOnly)))
    {
        fileWithData.readAll();
        fileWithData.close();
    }
    else
    {
        /*clear code*/
    }

    return;
}
