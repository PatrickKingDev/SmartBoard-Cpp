#include "motivationallist.h"
#include "motivationallistbutton.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QDebug>

MotivationalList::MotivationalList(QWidget *parent, QMap<QString, int> *list) : QWidget(parent){
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(0);

    QVBoxLayout *listLayout = new QVBoxLayout();

    for (int i = 0; i < list->count(); ++i){
        QHBoxLayout *itemLayout = new QHBoxLayout();
        ScaleTextLabel *itemLabel = new ScaleTextLabel(list->keys().at(i));
        MotivationalListButton *itemButton = new MotivationalListButton(list->values().at(i));

        itemLayout->addWidget(itemLabel);
        itemLayout->addWidget(itemButton);
        itemLayout->setStretch(0, 80);
        itemLayout->setStretch(1, 20);

        listLayout->addLayout(itemLayout);
        listLayout->setStretch(i, 1);
    }

    layout->addLayout(listLayout);
}
