#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <iostream>

class DBConnector
{
public:
    DBConnector();
    void getAllCars();
};

#endif // DBCONNECTOR_H
