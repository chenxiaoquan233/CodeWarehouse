#include "langitem.h"
#include "ui_langitem.h"
#include <QFile>

LangItem::LangItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LangItem)
{
    ui->setupUi(this);
}

LangItem::~LangItem()
{
    delete ui;
}

void LangItem::init(QString name, QString dirPath)
{
    this->dirPath = dirPath;
    this->name = name;

    setPic();
    setName();
    QImage del(":/pngs/del.png");
    del = del.scaled(QSize(DelPicWidth, DelPicWidth), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    //ui->del->setScaledContents(true);
    ui->del->setIcon(QPixmap::fromImage(del));
}

void LangItem::setPic()
{
    QString picPath = dirPath + "/lang.png";
    QFile imageFile(picPath);
    if(imageFile.exists())
    {
        QImage image(picPath);
        image = image.scaled(LangPicWidth, LangPicWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        //ui->langPic->setScaledContents(true);
        ui->langPic->setPixmap(QPixmap::fromImage(image));
    }
    else
        ui->langPic->setText(name);
}

void LangItem::setName()
{
    ui->langName->setText(name);
}

QPushButton* LangItem::getDelBtn()
{
    return ui->del;
}

void LangItem::rmLangDir()
{
    QDir rmDir(dirPath);
    rmDir.removeRecursively();
}
