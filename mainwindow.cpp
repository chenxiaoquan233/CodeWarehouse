#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "langitem.h"
#include "newlang.h"

MainWindow::MainWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initTitleBar();
    initConnect();
    initStyle();

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
    m_titleBar->setTitleWidth(280);
}

void MainWindow::initConnect()
{
    connect(ui->add, SIGNAL(clicked(bool)), this, SLOT(addNewLang()));
}

void MainWindow::initStyle()
{
    ui->langList->setStyleSheet("QListWidget::item:selected{background:#EAE0C1;}");

    ui->langList->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{width:6px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;padding-top:2px; padding-bottom:2px;}"
                                                     "QScrollBar::handle:vertical{width:6px;background:rgba(0,0,0,10%);border-radius:3px;min-height:20;}"
                                                     "QScrollBar::handle:vertical:hover{width:6px;background:rgba(0,0,0,30%);border-radius:3px;min-height:20;}"
                                                     "QScrollBar::add-line:vertical{height:0px;width:0px;subcontrol-position:bottom;}"
                                                     "QScrollBar::sub-line:vertical{height:0px;width:0px;subcontrol-position:top;}"
                                                     "QScrollBar::add-line:vertical:hover{height:0px;width:0px;subcontrol-position:bottom;}"
                                                     "QScrollBar::sub-line:vertical:hover{height:0px;width:0px;subcontrol-position:top;}"
                                                     "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,3%);border-radius:3px;}");
}

void MainWindow::setConfig(config* conf)
{
    this->conf = conf;
}

void MainWindow::init()
{
    addLangs(conf->getDataDir());
}

void MainWindow::addLangs(const QDir& langDir)
{
    itemMapper = new QSignalMapper(this);

    QFileInfoList langDirs = langDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    for(const auto &dir : langDirs)
    {
        QString langName = dir.baseName();
        QString langPath = dir.absoluteFilePath();

        addLangItem(langName, langPath);
    }
    connect(itemMapper, SIGNAL(mapped(QObject*)), this, SLOT(rmLang(QObject*)));
}

void MainWindow::addLangItem(QString name, QString path)
{
    LangItem* langItem = new LangItem();
    langItem->init(name, path);
    langItem->setStyleSheet("border-style:none;");

    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(QSize(50, 70));

    ui->langList->addItem(item);
    ui->langList->setItemWidget(item, langItem);

    connect(langItem->getDelBtn(), SIGNAL(clicked(bool)), itemMapper, SLOT(map()));
    itemMapper->setMapping(langItem->getDelBtn(), (QObject*)item);
    langItemMap.insert({item, langItem});
    //connect(langItem->getDelBtn(), SIGNAL(clicked(bool)), langItem, SLOT(rmLangDir()));
}

void MainWindow::addNewLang()
{
    newLang = new NewLang();
    newLang->setConfig(conf);
    newLang->setWindowModality(Qt::ApplicationModal);
    newLang->show();
    qDebug() << "end";
}

void MainWindow::rmLang(QObject* item)
{
    QMessageBox::StandardButton box;
    box = QMessageBox::question(this, "Hint!", "Do you want to remove this warehouse?", QMessageBox::Yes|QMessageBox::No);
    if(box==QMessageBox::No)
       return;
    for(int i = 0; i < ui->langList->count(); ++i)
    {
        if(ui->langList->item(i) == (QListWidgetItem*)item)
        {
            ui->langList->takeItem(i);
        }
    }

    langItemMap[(QListWidgetItem*)item]->rmLangDir();
}
