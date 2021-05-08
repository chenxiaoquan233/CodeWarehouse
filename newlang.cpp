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
    m_titleBar->hideMinBtn();
    m_titleBar->hideCloseBtn();

    initConnect();
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

void NewLang::initConnect()
{
    connect(ui->cancel, SIGNAL(clicked(bool)), this, SLOT(onCancelButtonClicked()));
}

void NewLang::onCancelButtonClicked()
{
    close();
}

void NewLang::onBrowseButtonClicked()
{

}

void NewLang::onOKButtonClicked()
{

}
