#include <iostream>
#include "dbconnector.h"


//using namespace std;

int main()
{
    //tests
    DBConnector dbconnector = DBConnector();
//    qDebug() << dbconnector.insertUser("testuser3", "password"); //Test: User einfügen

    //Test: Erste Zeile von Car
//    auto l = dbconnector.getAllCars();
//    auto t = l.front();
//    qDebug() << std::get<1>(t) << "\t" << std::get<2>(t);

//    auto p = dbconnector.getUserById(2); //Test: Userid 2 ausgeben

    return 0;
}
