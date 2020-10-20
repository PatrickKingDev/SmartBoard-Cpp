#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Test Zone

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

void MainWindow::on_pushButton_clicked()
{
    setButtonText(ui->pushButton);
}

void MainWindow::on_pushButton_2_clicked()
{
    setButtonText(ui->pushButton_2);
}

void MainWindow::on_pushButton_3_clicked()
{
    setButtonText(ui->pushButton_3);
}


void MainWindow::on_pushButton_4_clicked()
{
    setButtonText(ui->pushButton_4);
}

void MainWindow::setButtonText(QPushButton *button){
    QStringList textList = button->text().split("/");
    QString text = QString::number(textList.first().toInt() + 1);
    button->setText(text + "/" + textList.last());
}
