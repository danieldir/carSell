#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "dbconnector.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_Suche_clicked();

    void on_erstellen_clicked(DBConnector dbconnector);

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
