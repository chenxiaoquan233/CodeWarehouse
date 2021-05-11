#include "newlang.h"
#include "ui_newlang.h"
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>

NewLang::NewLang(QWidget *parent) :
    BaseWindow(parent),
    ui(new Ui::NewLang)
{
    ui->setupUi(this);
    initTitleBar();
    m_titleBar->hideMinBtn();
    m_titleBar->hideCloseBtn();

    initConnect();
}

NewLang::~NewLang()
{
    delete ui;
}

void NewLang::setConfig(config* conf)
{
    this->conf = conf;
}

void NewLang::initTitleBar()
{
    m_titleBar->setTitleContent(QStringLiteral("Add Warehouse"));
    m_titleBar->setTitleWidth(this->width());
}

void NewLang::initConnect()
{
    connect(ui->cancel, SIGNAL(clicked(bool)), this, SLOT(onCancelButtonClicked()));
    connect(ui->browse, SIGNAL(clicked(bool)), this, SLOT(onBrowseButtonClicked()));
    connect(ui->OK, SIGNAL(clicked(bool)), this, SLOT(onOKButtonClicked()));
}

void NewLang::onCancelButtonClicked()
{
    close();
}

void NewLang::onBrowseButtonClicked()
{
    QString tmpPath = QFileDialog::getOpenFileName(this, "choose icon", QStandardPaths::writableLocation(QStandardPaths::HomeLocation), "image(*.png)");
    if(!tmpPath.isEmpty())
    {
        ui->path->setText(tmpPath);
        QImage icon(tmpPath);
        icon = icon.scaled(QSize(previewWidth, previewWidth), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->preview->setPixmap(QPixmap::fromImage(icon));
    }
}

void NewLang::onOKButtonClicked()
{
    qDebug() << ui->name->toPlainText();
    if(ui->name->toPlainText().isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Warning, "Missing Information", "Please input warehouse name!", QMessageBox::Ok, this);
        msgBox.exec();
        return;
    }

    QString path = conf->getDataPath() + "/" + ui->name->toPlainText();

    QDir newWarehouseDir(path);
    if(newWarehouseDir.exists())
    {
        QMessageBox msgBox(QMessageBox::Warning, "Cannot create warehouse", "Folder with the same name already exists!", QMessageBox::Ok, this);
        msgBox.exec();
        return;
    }

    newWarehouseDir.mkdir(path);

    if(!ui->path->toPlainText().isEmpty())
    {
        QFile::copy(ui->path->toPlainText(), path + "/lang.png");
    }
}
