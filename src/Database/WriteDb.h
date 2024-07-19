//
// Created by Eux on 19/07/2024.
//

#ifndef CODE_BREW_WRITEDB_H
#define CODE_BREW_WRITEDB_H

#include "MenuFunctions.h"
#include "Database.h"

using namespace std;

class WriteDb : Database {
private:
    vector<string> rawData; // This is the raw data from the txt file
    // vector<Order> dataFromProgram; // This is the data that will be used in the program
public:
    void addOrderToDb(vector<Order> &order); // Raw Data
    void addRawProfitsToDb(vector<Order> &order);
    void addDataToDb(); // Pretty Data
    void deleteOrderFromDb(int index);
    void setDataFromProgram(vector<Order> &order);
};

#endif //CODE_BREW_WRITEDB_H
