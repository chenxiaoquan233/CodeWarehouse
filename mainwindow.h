#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtUiTools>
#include <QTextBrowser>
#include <QLabel>
#include <QMainWindow>
#include "config.h"
#include "basewindow.h"
#include "newlang.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public BaseWindow
{
    Q_OBJECT

public:
    void addLangs(const QDir& langDir);
    void addLangItem(QString picPath, QString name);
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void addNewLang();

private:
    NewLang* newLang;

    void initTitleBar();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
