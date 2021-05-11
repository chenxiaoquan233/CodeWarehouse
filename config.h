#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QFile>
#include <QJsonParseError>
#include <QtCore/QtCore>
#include <QDebug>


class config
{
public:
    config();
    virtual ~config();

    void CreateFile();
    QString getDataPath();
    QDir getDataDir();

private:
    QString configPath;
    QString configFileName;
    QString dataPath;
    QFile configFile;
    QDir configDir;
    QDir dataDir;
    QJsonDocument jsonConfig;
};

#endif // CONFIG_H
