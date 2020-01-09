#ifndef DIALOG31_H
#define DIALOG31_H

#include <QDialog>

namespace Ui {
class Dialog31;
}

class Dialog31 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog31(QWidget *parent = 0);
    ~Dialog31();

private:
    Ui::Dialog31 *ui;
};

#endif // DIALOG31_H
