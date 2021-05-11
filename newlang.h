#ifndef NEWLANG_H
#define NEWLANG_H

#include "basewindow.h"
#include <QWidget>
#include "config.h"

namespace Ui {
    class NewLang;
}

class NewLang : public BaseWindow
{
    Q_OBJECT
public:
    void setConfig(config* conf);
    explicit NewLang(QWidget* parent = 0);
    ~NewLang();

private slots:
    void onCancelButtonClicked();
    void onBrowseButtonClicked();
    void onOKButtonClicked();

private:
    config* conf;
    static constexpr int previewWidth = 110;

    void initTitleBar();
    void initConnect();
    Ui::NewLang *ui;
};

#endif // NEWLANG_H
