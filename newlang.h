#ifndef NEWLANG_H
#define NEWLANG_H

#include "basewindow.h"
#include <QWidget>

namespace Ui {
    class NewLang;
}

class NewLang : public BaseWindow
{
    Q_OBJECT
public:
    explicit NewLang(QWidget* parent = 0);
    ~NewLang();

private slots:
    void onCancelButtonClicked();
    void onBrowseButtonClicked();
    void onOKButtonClicked();

private:
    void initTitleBar();
    Ui::NewLang *ui;
};

#endif // NEWLANG_H
