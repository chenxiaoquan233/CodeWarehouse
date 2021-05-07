#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "basetitlebar.h"

class BaseWindow : public QWidget
{
    Q_OBJECT

public:
    BaseWindow(QWidget *parent = 0);
    ~BaseWindow();

private:

    void initTitleBar();

private slots:
    void onButtonMinClicked();
    void onButtonCloseClicked();

protected:
    BaseTitleBar* m_titleBar;

};

#endif // BASEWINDOW_H
