#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "motivationallist.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Test Zone
    QMap<QString, int> *motivationalList = new QMap<QString, int>();
    motivationalList->insert("KingList", 2);
    motivationalList->insert("Lecture", 4);
    motivationalList->insert("Projet Autre", 1);
    motivationalList->insert("Sport", 1);

    MotivationalList *list = new MotivationalList(this, motivationalList);

    ui->gridMotivationalList->addWidget(list);

    //Set Timer
    QTimer * ETTimer = new QTimer(this);
    connect(ETTimer,SIGNAL(timeout()),this,SLOT(updateTimeLabel()));
    ETTimer->start(1000);

    //Set Scroller
    //QScroller *scroller = QScroller::scroller(ui->scrollAreaWidgetContents);
    //QScroller::grabGesture(ui->scrollAreaWidgetContents, QScroller::LeftMouseButtonGesture);
    //scroller->scrollTo(QPointF(100,100));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::adjustSizes(){
    ui->label_2->setText(QString::number(ui->scrollArea->width()));
    ui->scrollAreaWidgetContents->setMinimumWidth((ui->scrollArea->width()+5)*2);
}

void MainWindow::on_close_btn_clicked()
{
    QApplication::exit();
}

void MainWindow::updateTimeLabel(){
    QString text = QTime::currentTime().toString("hh:mm");
    ui->lbl_time->setText(text);
}

//void MainWindow::setButtonText(QPushButton *button){
//    QStringList textList = button->text().split("/");
//    QString text = QString::number(textList.first().toInt() + 1);
//    button->setText(text + "/" + textList.last());
//}
