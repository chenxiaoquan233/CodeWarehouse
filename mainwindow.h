#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtUiTools>
#include <QTextBrowser>
#include <QLabel>
#include <QMainWindow>
#include "config.h"
#include "basewindow.h"
#include "newlang.h"
#include "langitem.h"
#include <unordered_map>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public BaseWindow
{
    Q_OBJECT

public:
    void init();
    void setConfig(config* conf);
    void addLangs(const QDir& langDir);
    void addLangItem(QString picPath, QString name);
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void addNewLang();
    void rmLang(QObject* item);

private:
    QSignalMapper* itemMapper;
    config* conf;
    NewLang* newLang;

    std::unordered_map<QListWidgetItem*, LangItem*> langItemMap;

    void initTitleBar();
    void initConnect();
    void initStyle();

    void delLang();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
