#include "newlang.h"
#include "ui_newlang.h"
#include <QFile>
#include <QDebug>

NewLang::NewLang(QWidget *parent) :
    BaseWindow(parent),
    ui(new Ui::NewLang)
{
    ui->setupUi(this);
    initTitleBar();
}

NewLang::~NewLang()
{
    delete ui;
}

void NewLang::initTitleBar()
{
    m_titleBar->setTitleContent(QStringLiteral("Add Warehouse"));
    m_titleBar->setTitleWidth(this->width());
}

void NewLang::onCancelButtonClicked()
{

}

void NewLang::onBrowseButtonClicked()
{

}

void NewLang::onOKButtonClicked()
{

}
