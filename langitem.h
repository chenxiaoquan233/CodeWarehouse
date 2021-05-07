#ifndef LANGITEM_H
#define LANGITEM_H

#include <QWidget>

namespace Ui {
    class LangItem;
}

class LangItem : public QWidget
{
    Q_OBJECT
public:
    void init(QString picPath, QString name);
    explicit LangItem(QWidget* parent = 0);
    ~LangItem();
private:
    Ui::LangItem *ui;

    void setPic(QString picPath, QString name);
    void setName(QString name);
};

#endif // LANGITEM_H
