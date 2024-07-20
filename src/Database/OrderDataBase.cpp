#include <iostream>
#include <fstream>
#include "ReadDb.h"
#include "WriteDb.h"
#include "MenuFunctions.h"
using namespace std;

void ReadDb::readDb() {

    ifstream file(absoluteRawFilePath);
    string line;

    while (getline(file, line)) {
        rawData.push_back(line);
    }

    if (rawData.empty()) {
        cout << "No orders found" << endl;
        return;
    }

    string orderName, orderSize, orderPrice, orderQuantity;
    double price;
    int quantity;
    for (string &i : rawData) {
        stringstream ss(i);
        getline(ss, orderName, ',');
        getline(ss, orderSize, ',');
        getline(ss, orderPrice, ',');
        getline(ss, orderQuantity, ',');

        price = stod(orderPrice);
        quantity = stoi(orderQuantity);

        dataFromProgram.emplace_back(orderName, orderSize, price, quantity);
    }
    file.close();
}

void ReadDb::displayAllOrderFromDb() {
    ifstream file(absolutePath);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
}

void WriteDb::addOrderToDb(vector<Order> &order) {
    ofstream file(absoluteRawFilePath, ios::app); // save to RawOrders.txt

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
    }

    for (Order &i : order) {
        file << i.name << "," << i.size << "," << i.price << "," << i.quantity << endl;
    }
    file.close();

}

void WriteDb::addRawProfitsToDb(vector<Order> &order) {
    ofstream file(absolutePath, ios::app);
    double rawProfits = 0;
    for (Order &i : order) {
        rawProfits += (i.price * i.quantity);
    }

    file << "\nTotal Profits: " << rawProfits << endl;
    file.close();
}

void WriteDb::addDataToDb() {
    ReadDb readFile;
    ofstream file(absolutePath, ios::app); // save to Orders.txt

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
    }

    for (Order &i : this->dataFromProgram) {
        if (i.size == "Large" && i.price == 0.00) {
            // Probably a file << "Order Number: " << i.orderNumber << endl;
            file << "Name: " << i.name  << " | Price: " << i.price << " | Quantity: " << i.quantity << endl;
            return;
        }
        file << "Name: " << i.name << " | Size: " << i.size << " | Price: " << i.price << " | Quantity: " << i.quantity << endl;
    }
    file.close();
}

vector<Order> ReadDb::getOrderData() {
    return this->dataFromProgram;
}

void WriteDb::setDataFromProgram(vector<Order> &order) {
    this->dataFromProgram = order;
}