#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "langitem.h"
#include "newlang.h"

MainWindow::MainWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::MainWindow)
{
    initTitleBar();

    ui->setupUi(this);
    //setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setWindowIcon(QIcon(":/pngs/icon.png"));

    ui->langList->setStyleSheet("QListWidget::item:selected{background:#EAE0C1;}");

    ui->langList->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{width:6px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;padding-top:2px; padding-bottom:2px;}"
                                                     "QScrollBar::handle:vertical{width:6px;background:rgba(0,0,0,10%);border-radius:3px;min-height:20;}"
                                                     "QScrollBar::handle:vertical:hover{width:6px;background:rgba(0,0,0,30%);border-radius:3px;min-height:20;}"
                                                     "QScrollBar::add-line:vertical{height:0px;width:0px;subcontrol-position:bottom;}"
                                                     "QScrollBar::sub-line:vertical{height:0px;width:0px;subcontrol-position:top;}"
                                                     "QScrollBar::add-line:vertical:hover{height:0px;width:0px;subcontrol-position:bottom;}"
                                                     "QScrollBar::sub-line:vertical:hover{height:0px;width:0px;subcontrol-position:top;}"
                                                     "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,3%);border-radius:3px;}");

    connect(ui->add, SIGNAL(clicked(bool)), this, SLOT(addNewLang()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTitleBar()
{
    m_titleBar->setTitleIcon(":/pngs/icon.png");
    m_titleBar->setTitleContent(QStringLiteral("CodeWarehouse"));
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
    langItem->setStyleSheet("border-style:none;");

    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(QSize(50, 70));

    ui->langList->addItem(item);
    ui->langList->setItemWidget(item, langItem);
}

void MainWindow::addNewLang()
{
    newLang = new NewLang();
    newLang->setWindowModality(Qt::ApplicationModal);
    newLang->show();
}
