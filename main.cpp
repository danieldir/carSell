#include <iostream>
#include "dbconnector.h"

//using namespace std;

int main()
{
    DBConnector dbconnector = DBConnector();
    dbconnector.getAllCars();
    return 0;
}
