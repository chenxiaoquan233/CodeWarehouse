#include "basewindow.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <QFile>

BaseWindow::BaseWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setStyleSheet("background-color:#F0ECE1;");
    initTitleBar();
}

BaseWindow::~BaseWindow()
{

}

void BaseWindow::initTitleBar()
{
    m_titleBar = new BaseTitleBar(this);
    m_titleBar->move(0, 0);

    connect(m_titleBar, SIGNAL(signalButtonMinClicked()), this, SLOT(onButtonMinClicked()));
    connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));

}

void BaseWindow::onButtonMinClicked()
{
    if (Qt::Tool == (windowFlags() & Qt::Tool))
    {
        hide();
    }
    else
    {
        showMinimized();
    }
}

void BaseWindow::onButtonCloseClicked()
{
    close();
}
