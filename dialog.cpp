#include "dialog.h"
#include "ui_dialog.h"
#include "dialog2.h"
#include "dialog31.h"
#include <QtWidgets>
#include <QPixmap>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

ui->comboMark->addItem(" Audi");
ui->comboMark->addItem(" Mercedes ");
ui->comboMark->addItem(" Volkswagen");
ui->comboMark->addItem(" Toyota");

ui->comboModel->addItem(" Q5");
ui->comboModel->addItem(" Corolla");
ui->comboModel->addItem(" A205");
ui->comboModel->addItem(" Limousine");
ui->comboBox->addItem(" Gebraucht");
ui->comboBox->addItem(" Neu");

ui->comboColor->addItem(" blau");
ui->comboColor->addItem(" rot");
ui->comboColor->addItem(" Gruen");
ui->comboColor->addItem(" Gelb");
ui->comboColor->addItem(" Weiss");

for ( int i=1000; i<20000; i++)
{
   i= i+ 500;
 ui->comboPreis->addItem(QString::number(i)); 
}

//QColor couleur = QColorDialog::getColor(Qt::white, this);

  // QPalette palette;
  // palette.setColor(QPalette::ButtonText, couleur);
   //ui->comboColor->setPalette(palette);

ui->comboMark_2->addItem(" Audi");
ui->comboMark_2->addItem(" Mercedes ");
ui->comboMark_2->addItem(" Volkswagen");
ui->comboMark_2->addItem(" Toyota");

ui->comboModel_2->addItem(" Q5");
ui->comboModel_2->addItem(" Corolla");
ui->comboModel_2->addItem(" A205");
ui->comboModel_2->addItem(" Limousine");
ui->comboBox_2->addItem(" Gebraucht");
ui->comboBox_2->addItem(" Neu");

//ui-> ->addItem(" blau");
//ui->comboColor_2->addItem(" rot");
//ui->comboColor_2->addItem(" Gruen");
//ui->comboColor_2->addItem(" Gelb");
ui->comboKraft->addItem(" Benzin");
ui->comboKraft->addItem(" Diesel");
ui->comboKraft->addItem(" Elektroauto");

for ( int i=1000; i<20000; i++)
{
   i= i+ 500;
 //ui->comboPreis_2->addItem(QString::number(i));
}

QPixmap pix("home/Persönlicher_Ordner/bild.jpg");
ui->label_pic->setPixmap(pix.scaled(100,100, Qt::KeepAspectRatio));


}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{

}


void Dialog::on_Suche_clicked()
{
    QMessageBox::information(this, "Auto Kaufen", " Suchkriterien bestätigen");
    hide();
    Dialog2 dialog2;

   dialog2.setModal(true); // form.setWindowModality(true);  //setModal(true);
    dialog2.exec();

}

void Dialog::on_erstellen_clicked()
{
    QMessageBox::information(this, "Auto Verkaufen", "Suchkriterien wurde bestätigen");
    hide();
    Dialog31 dialog31;

   dialog31.setModal(true);
    dialog31.exec();
}