#include "dialog3.h"
#include "ui_dialog3.h"
#include <QtWidgets>
#include "dialog.h"
#include "MyWindow2.h"


Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);

    QLineEdit *name = new QLineEdit;
    QLineEdit *surname = new QLineEdit;
    QLineEdit *number = new QLineEdit;
    QLineEdit *city = new QLineEdit;
    QLineEdit *passwort = new QLineEdit;
    QLineEdit *Email = new QLineEdit;
    QLineEdit *wdh_passwort = new QLineEdit;
     QLineEdit *username = new QLineEdit;

       QFormLayout *formLayout = new QFormLayout;
       formLayout->addRow("Name", name);
       formLayout->addRow("surname", surname);
       formLayout->addRow("number", number);
       formLayout->addRow("city", city);
       formLayout->addRow("passwort", passwort);
       formLayout->addRow("Email", Email);
       formLayout->addRow("wdh_passwort", wdh_passwort);
       formLayout->addRow("username", username);

       // Création du layout principal de la fenêtre (vertical)

       QVBoxLayout *layoutPrincipal = new QVBoxLayout;
   layoutPrincipal->addLayout(formLayout); // Ajout du layout de formulaire

       //QPushButton *boutonQuitter = new QPushButton("Quitter");
      // QWidget::connect(boutonQuitter, SIGNAL(clicked()), &app, SLOT(quit()));
   //layoutPrincipal->addWidget(boutonQuitter); // Ajout du bouton

      // Dialog3.setLayout(layoutPrincipal);

}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::on_submit_clicked()
{
     QMessageBox::information(this, "Login", "Login Sucessfull, jetzt anmelden sie sich neue mit Username:");
    // Dialog3 *dialog32= new Dialog3;
     hide();
     MyWindow2 *wind= new MyWindow2;
      wind->show();



}
