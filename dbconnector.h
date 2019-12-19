#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <iostream>
#include <map>
#include <QCryptographicHash>

class DBConnector
{
public:
    DBConnector();
    std::list<std::tuple<int, QString, QString, QString, int, QString, int> > getAllCars();
    std::map<int,std::pair<QString, QString> > getAllUsers();
    std::pair<QString, QString> getUserById(int id);
    QString getHashByUsername(QString username);
    bool insertUser(QString username, QString password);
};

#endif // DBCONNECTOR_H
