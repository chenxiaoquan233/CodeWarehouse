#ifndef BASETITLEBAR_H
#define BASETITLEBAR_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class BaseTitleBar : public QWidget
{
    Q_OBJECT

public:
    BaseTitleBar(QWidget *parent = NULL);
    ~BaseTitleBar();

    void setTitleIcon(QString filePath);
    void setTitleContent(QString titleContent);
    void setTitleWidth(int width);

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void initControl();
    void initConnections();
    void initButtonImg();

signals:
    void signalButtonMinClicked();
    void signalButtonCloseClicked();

private slots:
    void onButtonMinClicked();
    void onButtonCloseClicked();

private:
    QLabel* icon;
    QLabel* title;
    QLabel* space;
    QPushButton* minBtn;
    QPushButton* closeBtn;

    bool isPressed;
    QPoint startMovePos;
};

#endif // BASETITLEBAR_H
