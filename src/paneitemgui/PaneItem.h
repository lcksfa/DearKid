// PenalItem 类：
#ifndef PANELITEM_H
#define PANELITEM_H
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QObject>
class GPanelItem : public QWidget
{
    Q_OBJECT
public:
    GPanelItem(QWidget *parent = 0)
        : QWidget(parent)
    {
        increaseButton = new QPushButton(QString(tr("<")), this);
        QObject::connect(increaseButton, SIGNAL(clicked()), this, SLOT(increaseNum()));
        decreaseButton = new QPushButton(QString(tr(">")), this);
        QObject::connect(decreaseButton, SIGNAL(clicked()), this, SLOT(decreaseNum()));
        value = 0;
        numLabel = new QLabel();
        numLabel->setNum(value);
    }
    ~GPanelItem()
    {
        delete increaseButton;
        delete decreaseButton;
        delete numLabel;
    }

public:
    void reset()
    {
        setValue(0);
    }
    void setValue(int value)
    {
        this->value = value;
        numLabel->setNum(value);
    }
private slots:
    void increaseNum()
    {
        if (value < 9)
            value++;
        numLabel->setNum(value);
    }
    void decreaseNum()
    {
        if (value > 0)
            value--;
        numLabel->setNum(value);
    }

public:
    QPushButton *getIncreaseButton()
    {
        return increaseButton;
    }
    QPushButton *getDecreaseButton()
    {
        return decreaseButton;
    }
    QLabel *getNumLabel()
    {
        return numLabel;
    }

private:
    QPushButton *increaseButton;
    QPushButton *decreaseButton;
    QLabel *numLabel;

private:
    int value;
};
#endif