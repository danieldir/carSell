#include "MyWindow2.h"
#include "ui_mywindow2.h"
#include <QtWidgets>


MyWindow2::MyWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow2)
{
    ui->setupUi(this);
}

MyWindow2::~MyWindow2()
{
    delete ui;
}

void MyWindow2::on_pushButton_clicked()
{
    QString username = ui->username->text();
    QString Passwort = ui->passwort->text();


    if(username== "foka" && Passwort== "foka")
    {
       // QMessageBox::information(this, "Login", "Username and Paswort is correct");
        QMessageBox::information(this, "Anmeldung erfolgreich", "Willkommen bei CarSell " + username);
        hide();
        dialog = new Dialog(this);
        dialog->show();

    } else{

      QMessageBox::warning(this, "Anmeldung", "Username and Paswort is not correct");
    }

}

void MyWindow2::on_SignUp_clicked()
{
        QMessageBox::information(this, "Login", "Loggen sie sich to Carsell");
        hide();
        dialog3 = new Dialog3(this);
        dialog3->show();

}
