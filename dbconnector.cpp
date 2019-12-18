#include "dbconnector.h"
DBConnector::DBConnector()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("remotemysql.com");
    db.setPort(3306);
    db.setDatabaseName("pztczcJad0");
    db.setUserName("pztczcJad0");
    db.setPassword("F522g2piJ5");
    bool ok = db.open();

}

void DBConnector::getAllCars(){
    QSqlQuery query;
    query.exec("select * from Auto");
    while(query.next()) {
        int id = query.value(0).toInt();
        QString marke = query.value(1).toString();
        QString modell = query.value(2).toString();
        QString farbe = query.value(3).toString();
        QString preis = query.value(4).toString();
        QString kraftstoffart = query.value(5).toString();
        int verkaeuferid = query.value(7).toInt();
        qDebug() << id << "\t" << marke << "\t" << modell << "\t" << farbe << "\t" << preis << "\t" << kraftstoffart << "\t" << verkaeuferid;
    }
}
