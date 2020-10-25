#ifndef MOTIVATIONALLIST_H
#define MOTIVATIONALLIST_H

#include <QWidget>

class MotivationalList : public QWidget{

public :
    MotivationalList(QWidget *parent = 0, QMap<QString, int> *list = 0);
    ~MotivationalList(){}
};

#endif // MOTIVATIONALLIST_H
