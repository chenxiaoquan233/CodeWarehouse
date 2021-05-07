#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "langitem.h"

MainWindow::MainWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::MainWindow)
{
    initTitleBar();

    ui->setupUi(this);
    ui->langList->setStyleSheet("background-color:#FDF6E3;");
    ui->add->setStyleSheet("QPushButton{border-style:none; background-color:#AC9D57;}"
                             "QPushButton:hover{border-style:none; background-color:#8B7E44;}");
    ui->filter->setStyleSheet("QTextEdit{border-style:solid;border-width:1px;border-color:#D4B189;background-color:#DDD6C1;}");
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setWindowIcon(QIcon(":/pngs/icon.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTitleBar()
{
    m_titleBar->setTitleIcon(":/pngs/icon.png");
    m_titleBar->setTitleContent(QStringLiteral("CodeWarehouse"));
    qDebug() << this->width();
    m_titleBar->setTitleWidth(280);
}

void MainWindow::addLangs(const QDir& langDir)
{
    QFileInfoList langDirs = langDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    for(const auto &dir : langDirs)
    {
        QString langName = dir.baseName();
        QString langPicPath = dir.absoluteFilePath() + "/lang.png";

        addLangItem(langPicPath, langName);
    }
}

void MainWindow::addLangItem(QString picPath, QString name)
{
    LangItem* langItem = new LangItem();
    langItem->init(picPath, name);

    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(QSize(50, 70));

    ui->langList->addItem(item);
    ui->langList->setItemWidget(item, langItem);
}
