#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void adjustSizes();

private slots:
    void on_close_btn_clicked();
    void updateTimeLabel();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
