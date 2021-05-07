#include "basetitlebar.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QFile>
#include <QMouseEvent>
#include <QDebug>

#define BUTTON_HEIGHT 30
#define BUTTON_WIDTH 45
#define TITLE_HEIGHT 30
#define IMG_WIDTH 19
#define SPACE_WIDTH 10

BaseTitleBar::BaseTitleBar(QWidget *parent)
    : QWidget(parent)
    , isPressed(false)
{
    setStyleSheet("background-color:#F0ECE1;");
    initControl();
    initButtonImg();
    initConnections();
}

void BaseTitleBar::initButtonImg()
{
    QImage min(":/pngs/min.png");
    QImage close(":/pngs/close.png");

    minBtn->setStyleSheet("QPushButton{border-style:none; background-color:#F0ECE1;}"
                                "QPushButton:hover{border-style:none; background-color:#D9D2C2;}");
    minBtn->setIcon(QPixmap::fromImage(min));
    minBtn->setIconSize(QSize(IMG_WIDTH, IMG_WIDTH));

    closeBtn->setStyleSheet("QPushButton{border-style:none; background-color:#F0ECE1;}"
                                "QPushButton:hover{border-style:none; background-color:#E82635;}");
    closeBtn->setIcon(QPixmap::fromImage(close));
    closeBtn->setIconSize(QSize(IMG_WIDTH, IMG_WIDTH));
}

BaseTitleBar::~BaseTitleBar()
{

}

void BaseTitleBar::initControl()
{
    icon = new QLabel;
    title = new QLabel;
    space = new QLabel;

    minBtn = new QPushButton;
    closeBtn = new QPushButton;

    space->setFixedSize(QSize(SPACE_WIDTH, TITLE_HEIGHT));
    minBtn->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    closeBtn->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));

    title->setObjectName("TitleContent");
    minBtn->setObjectName("ButtonMin");
    closeBtn->setObjectName("ButtonClose");

    QHBoxLayout* mylayout = new QHBoxLayout(this);
    mylayout->addWidget(icon);
    mylayout->addWidget(space);
    mylayout->addWidget(title);

    mylayout->addWidget(minBtn);
    mylayout->addWidget(closeBtn);

    mylayout->setContentsMargins(10, 0, 0, 0);
    mylayout->setSpacing(0);

    title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setFixedHeight(TITLE_HEIGHT);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

void BaseTitleBar::initConnections()
{
    connect(minBtn, SIGNAL(clicked()), this, SLOT(onButtonMinClicked()));
    connect(closeBtn, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
}

void BaseTitleBar::setTitleIcon(QString filePath)
{
    QPixmap titleIcon(filePath);
    icon->setPixmap(titleIcon.scaled(25 , 25));
}

void BaseTitleBar::setTitleContent(QString titleContent)
{
    title->setText(titleContent);
}

void BaseTitleBar::setTitleWidth(int width)
{
    this->setFixedWidth(width);
}

void BaseTitleBar::mousePressEvent(QMouseEvent *event)
{
    isPressed = true;
    startMovePos = event->globalPos();

    return QWidget::mousePressEvent(event);
}

void BaseTitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressed)
    {
        QPoint movePoint = event->globalPos() - startMovePos;
        QPoint widgetPos = this->parentWidget()->pos();
        startMovePos = event->globalPos();
        this->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
    }
    return QWidget::mouseMoveEvent(event);
}

void BaseTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    isPressed = false;
    return QWidget::mouseReleaseEvent(event);
}

void BaseTitleBar::onButtonMinClicked()
{
    emit signalButtonMinClicked();
}

void BaseTitleBar::onButtonCloseClicked()
{
    emit signalButtonCloseClicked();
}
