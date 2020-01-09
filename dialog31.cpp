#include "dialog31.h"
#include "ui_dialog31.h"

Dialog31::Dialog31(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog31)
{
    ui->setupUi(this);
}

Dialog31::~Dialog31()
{
    delete ui;
}
