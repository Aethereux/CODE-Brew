#ifndef database_h
#define database_h

#include "../User UI/MenuFunctions.h"
#include "Database.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class ReadDb : Database {
private:
    vector<string> rawData; // This is the raw data from the txt file
    // vector<Order> dataFromProgram; // This is the data that will be used in the program
public:
    void readDb();
    void displayAllOrderFromDb();
    vector<Order> getOrderData();
};


#endif