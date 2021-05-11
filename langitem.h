#ifndef LANGITEM_H
#define LANGITEM_H

#include <QWidget>
#include <QPushButton>
#include <QDir>

namespace Ui {
    class LangItem;
}

class LangItem : public QWidget
{
    Q_OBJECT
public:
    void init(QString picPath, QString name);

    QPushButton* getDelBtn();

    explicit LangItem(QWidget* parent = 0);
    ~LangItem();
private:
    Ui::LangItem *ui;
    static constexpr int LangPicWidth = 40;
    static constexpr int DelPicWidth = 20;
    QString dirPath, name;
    void setPic();
    void setName();
public slots:
    void rmLangDir();
};

#endif // LANGITEM_H
