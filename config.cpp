#include "config.h"

config::config()
{
#ifdef _WIN32
    configPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/AppData/CodeWarehouse/config/";
    dataPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/AppData/CodeWarehouse/languages/";
#elif __linux__
    configPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/.config/CodeWarehouse";
    dataPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/.local/share/CodeWarehouse/";
#endif

    configFileName = configPath + "config.json";
    configDir.setPath(configPath);
    configFile.setFileName(configFileName);

    dataDir.setPath(dataPath);

    if(!configDir.exists())
    {
        configDir.mkdir(configPath);
    }
    configFile.open(QIODevice::ReadWrite);

    if(!dataDir.exists())
    {
        dataDir.mkdir(dataPath);
    }

    QByteArray configBuf = configFile.readAll();
    configFile.close();

    QJsonParseError jsonParseError;

    jsonConfig = QJsonDocument::fromJson(configBuf, &jsonParseError);
}

config::~config()
{
}

QDir config::getDataDir()
{
    return dataDir;
}

QString config::getDataPath()
{
    return dataPath;
}
