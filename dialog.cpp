#include "dialog.h"
#include "ui_dialog.h"
#include "dialog2.h"
#include "dialog31.h"
#include <QtWidgets>
#include <QPixmap>

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{

    DBConnector dbconnector = DBConnector();
    ui->setupUi(this);

//    ui->erstellen->connect(this, SIGNAL(clicked()), dbconnector, SLOT(on_erstellen_clicked()));

//    connect(ui->erstellen, SIGNAL(clicked()), this, SLOT(on_erstellen_clicked(dbconnector)));



    auto liste = dbconnector.getAllMarken();
    QString item;
    while(!liste.empty()) {
        item = liste.front();
        liste.pop_front();
        ui->comboMark->addItem(item);
    }

    liste = dbconnector.getAllModelle();
    while(!liste.empty()) {
        item = liste.front();
        liste.pop_front();
        ui->comboModel->addItem(item);
    }

    liste = dbconnector.getAllFarben();
    while(!liste.empty()) {
        item = liste.front();
        liste.pop_front();
        ui->comboColor->addItem(item);
    }

    for ( int i=1000; i<20000; i++)
    {
        i= i+ 500;
        ui->comboPreis->addItem(QString::number(i));
    }

    ui->linePreis->setValidator(new QIntValidator(0, 1000000, this));

    //QColor couleur = QColorDialog::getColor(Qt::white, this);

    // QPalette palette;
    // palette.setColor(QPalette::ButtonText, couleur);
    //ui->comboColor->setPalette(palette);

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

void Dialog::on_erstellen_clicked(DBConnector dbconnector)
{
    int vPreis;
    QString vMarke, vModell, vFarbe, vKraftstoff;
    vPreis = ui->linePreis->text().toInt();
    vMarke = ui->lineMarke->text();
    vModell = ui->lineModell->text();
    vFarbe = ui->lineFarbe->text();
    vKraftstoff = ui->comboKraft->currentText();
    qDebug() << vMarke << "\t" << vModell << "\t" << vFarbe << "\t" << vPreis << "\t" << vKraftstoff;
    dbconnector.insertCar(vMarke, vModell, vFarbe, vPreis, vKraftstoff, NULL, 0/*, UserID*/);

    QMessageBox::information(this, "Auto Verkaufen", "Ihr Auto wird hinzugefügt.");
    hide();
    Dialog31 dialog31;

    dialog31.setModal(true);
    dialog31.exec();
}
