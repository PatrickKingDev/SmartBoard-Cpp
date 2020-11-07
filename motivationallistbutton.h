#ifndef MOTIVATIONALLISTBUTTON_H
#define MOTIVATIONALLISTBUTTON_H

#include <QPushButton>
#include <QTimer>
#include <QDebug>

class MotivationalListButton : public QPushButton{
    static const int longPressDelay = 2000;
    const QString separator = "/";

public:
    explicit MotivationalListButton(const int _maximum, QWidget *parent = Q_NULLPTR)
        :QPushButton("",parent)
    {
        current = 0;
        maximum = _maximum;
        refreshText();
    }

protected:
    void mousePressEvent(QMouseEvent *) override{
        wasLongPress = false;
        initTimer();
    }
    void mouseReleaseEvent(QMouseEvent *) override{
        longPressTimer->stop();
        if(!wasLongPress){
            upgrade();
        }
    }

private:
    QTimer* longPressTimer;
    bool wasLongPress = false;
    int current;
    int maximum;

    void initTimer(){
        longPressTimer = new QTimer(this);
        longPressTimer->setInterval(longPressDelay);
        longPressTimer->setSingleShot(true);
        connect(longPressTimer,&QTimer::timeout,this,&MotivationalListButton::longPressEvent);
        longPressTimer->start();
    }

    void upgrade(){
        ++current;
        refreshText();
    }

    void downgrade(){
        --current;
        refreshText();
    }

    void refreshText(){
        this->setText(QString::number(current)+separator+QString::number(maximum));
    }

protected slots:
    void longPressEvent(){
        wasLongPress = true;
        downgrade();
    }
};

#endif // MOTIVATIONALLISTBUTTON_H
