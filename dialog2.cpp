#include "dialog2.h"
#include "ui_dialog2.h"
#include<QtWidgets>

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    
}

Dialog2::~Dialog2()
{
    delete ui;
}
