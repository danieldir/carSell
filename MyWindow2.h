#ifndef MYWINDOW2_H
#define MYWINDOW2_H

#include <QMainWindow>
#include <dialog.h>
#include <dialog2.h>
#include <dialog3.h>
#include <dialog31.h>


namespace Ui {
class MyWindow2;
}

class MyWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyWindow2(QWidget *parent = 0);
    ~MyWindow2();

private slots:
    void on_pushButton_clicked();

    void on_SignUp_clicked();

private:
    Ui::MyWindow2 *ui;
    MyWindow2 *wind;
    Dialog *dialog;
    Dialog *dialog32;
    Dialog2 *dialog2;
    Dialog3 *dialog3;
    Dialog31 *dialog31;

};

#endif // MYWINDOW2_H
