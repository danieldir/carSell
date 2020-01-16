#include "dialog.h"
#include "ui_dialog.h"
#include "dialog2.h"
#include "dialog31.h"
#include <QtWidgets>
#include <QPixmap>

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{

    DBConnector::connectToDB();
    ui->setupUi(this);

    ui->comboMark->addItem(NULL);
    auto liste = DBConnector::getAllMarken();
    QString item;
    while(!liste.empty()) {
        item = liste.front();
        liste.pop_front();
        ui->comboMark->addItem(item);
    }

    ui->comboModel->addItem(NULL);
    liste = DBConnector::getAllModelle();
    while(!liste.empty()) {
        item = liste.front();
        liste.pop_front();
        ui->comboModel->addItem(item);
    }

    ui->comboColor->addItem(NULL);
    liste = DBConnector::getAllFarben();
    while(!liste.empty()) {
        item = liste.front();
        liste.pop_front();
        ui->comboColor->addItem(item);
    }

    ui->comboKraft_2->addItem("");
    ui->comboKraft_2->addItem("Benzin");
    ui->comboKraft_2->addItem("Diesel");
    ui->comboKraft_2->addItem("Elektro");

    ui->lineSPreis->setValidator(new QIntValidator(0, 1000000, this));
    ui->lineVPreis->setValidator(new QIntValidator(0, 1000000, this));

    ui->comboKraft->addItem("Benzin");
    ui->comboKraft->addItem("Diesel");
    ui->comboKraft->addItem("Elektro");


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

    int sPreis;
    QString sMarke, sModell, sFarbe, sKraftstoff;
    sPreis = ui->lineSPreis->text().toInt();
    sMarke = ui->comboMark->currentText();
    sModell = ui->comboModel->currentText();
    sFarbe = ui->comboColor->currentText();
    sKraftstoff = ui->comboKraft_2->currentText();
    qDebug() << sMarke << "\t" << sModell << "\t" << sFarbe << "\t" << sPreis << "\t" << sKraftstoff;

    auto l = DBConnector::searchCar(sMarke, sModell, sFarbe, sPreis, sKraftstoff, 0);
    QString text;
    text = l.size();
    qDebug() << l.size();
    text.append(" Treffer gefunden.");
    QMessageBox::information(this, "Auto Kaufen", text);
    hide();
    Dialog2 dialog2;

    dialog2.setModal(true); // form.setWindowModality(true);  //setModal(true);
    dialog2.exec();

}

void Dialog::on_erstellen_clicked()
{

    int vPreis;
    QString vMarke, vModell, vFarbe, vKraftstoff;
    vPreis = ui->lineVPreis->text().toInt();
    vMarke = ui->lineMarke->text();
    vModell = ui->lineModell->text();
    vFarbe = ui->lineFarbe->text();
    vKraftstoff = ui->comboKraft->currentText();
    qDebug() << vMarke << "\t" << vModell << "\t" << vFarbe << "\t" << vPreis << "\t" << vKraftstoff;
    bool insert;
    insert = DBConnector::insertCar(vMarke, vModell, vFarbe, vPreis, vKraftstoff, NULL, 3);
    if(insert) {
        QMessageBox::information(this, "Auto verkaufen", "Ihr Auto wird hinzugefügt.");
        hide();
        Dialog31 dialog31;

        dialog31.setModal(true);
        dialog31.exec();
    } else {
        qDebug() << "DB connection error";
    }


}
