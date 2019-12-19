#include "dbconnector.h"
DBConnector::DBConnector()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("remotemysql.com");
    db.setPort(3306);
    db.setDatabaseName("pztczcJad0");
    db.setUserName("pztczcJad0");
    db.setPassword("F522g2piJ5");
    if(db.open()) {
        std::cout << "DB connected!" << std::endl;
    } else {
        std::cout << "DB not connected!" << std::endl;
    }

}

std::list<std::tuple<int, QString, QString, QString, int, QString, int> > DBConnector::getAllCars(){
    int id, preis, verkaeuferid;
    QString marke, modell, farbe, kraftstoffart;
    QSqlQuery query;
    std::list<std::tuple<int, QString, QString, QString, int, QString, int> > l;
    query.exec("select * from Auto");
    while(query.next()) {
        id = query.value(0).toInt();
        marke = query.value(1).toString();
        modell = query.value(2).toString();
        farbe = query.value(3).toString();
        preis = query.value(4).toInt();
        kraftstoffart = query.value(5).toString();
        verkaeuferid = query.value(7).toInt();
        qDebug() << id << "\t" << marke << "\t" << modell << "\t" << farbe << "\t" << preis << "\t" << kraftstoffart << "\t" << verkaeuferid;
        l.push_back(std::tuple<int, QString, QString, QString, int, QString, int>(id, marke, modell, farbe, preis, kraftstoffart, verkaeuferid));
    }
    return l;
}

std::map<int,std::pair<QString, QString> > DBConnector::getAllUsers(){
    int id;
    QString username, hash;
    QSqlQuery query;
    std::map<int,std::pair<QString, QString> > m;
    query.exec("select * from User");
    while(query.next()) {
        id = query.value(0).toInt();
        username = query.value(1).toString();
        hash = query.value(2).toString();
        m[id] = std::pair<QString, QString> (username, hash);
//        m.insert(std::pair<int, QString>((id, username));
    }
    return m;
}

std::pair<QString, QString> DBConnector::getUserById(int id) {
    QString username, hash;
    QSqlQuery query;
    query.prepare("select * from User where idUser = :idinput");
//    query.prepare("select * from User where idUser = 1");
    query.bindValue(":idinput", id);
    query.exec();
    query.next();
    if(query.isNull(id)) {
        qDebug() << "No User with this id!";
        return std::pair<QString, QString> ();
    }
    username = query.value(1).toString();
    hash = query.value(2).toString();
    qDebug() << username << hash;
    return std::pair<QString, QString> (username, hash);
}

QString DBConnector::getHashByUsername(QString username) {
    QSqlQuery query;
    query.prepare("select * from User where idUser = :usernameinput");
    query.bindValue(":usernameinput", username);
    query.exec();
    query.next();
    if(query.isNull(username)) {
        return NULL;
    }
    return query.value(2).toString();
}

bool DBConnector::insertUser(QString username, QString password) {
    QSqlQuery query;
    query.exec("select * from User");
    query.last();
    int id = query.value(0).toInt();
    id++;
    QString password_hash = QCryptographicHash::hash(
                QByteArray::fromStdString(password.toStdString()),
                QCryptographicHash::RealSha3_256).toBase64();
    query.prepare("INSERT INTO User (idUser, Username, passwort_hash) "
                  "VALUES (:idinput, :usernameinput, :hashinput)");
    query.bindValue(":idinput", id);
    query.bindValue(":usernameinput", username);
    query.bindValue(":hashinput", password_hash);
    return query.exec();
}
