#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Windows.h>
#include <QProcess>
#include <form.h>
#include <QDebug>
#include <QMouseEvent>
#include <QTime>
#include <QApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual void mousePressEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void sleep(unsigned int msec);

private:
    Ui::MainWindow *ui;
    Form *love;
    int flag;
};

#endif // MAINWINDOW_H
