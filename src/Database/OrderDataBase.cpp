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

    string diningOption, orderNumber, orderName, orderSize, orderPrice, orderQuantity;
    double price;
    int quantity, orderNum;

    for (string &i : rawData) {
        stringstream ss(i);
        getline(ss, diningOption, ',');
        getline(ss, orderNumber, ',' );
        getline(ss, orderName, ',');
        getline(ss, orderSize, ',');
        getline(ss, orderPrice, ',');
        getline(ss, orderQuantity, ',');

        orderNum = stoi(orderNumber);
        price = stod(orderPrice);
        quantity = stoi(orderQuantity);

        dataFromProgram.emplace_back(orderName, orderSize, price, quantity);
        dataFromProgram.back().orderNumber = orderNum;
        dataFromProgram.back().diningOption = diningOption;
    }
    file.close();
}

void WriteDb::addOrderToDb(vector<Order> &order) {
    ofstream file(absoluteRawFilePath, ios::app); // save to RawOrders.txt

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
    }

    for (Order &i : order) {
        file << i.diningOption << "," << i.orderNumber << ","<< i.name << "," << i.size << "," << i.price << "," << i.quantity << endl;
    }
    file.close();

}


void WriteDb::addDataToDb() {
    ReadDb readFile;
    ofstream file(absolutePath, ios::app); // save to Orders.txt
    double rawProfits = 0;
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return; // Ensure to exit the function if file opening fails
    }
    int orderNumber = dataFromProgram.back().orderNumber;
    string diningOption = dataFromProgram.back().diningOption;
    file << "--------------------------------------" << endl;
    file << "Dining Option: " << diningOption << endl << endl;
    for (Order &i : this->dataFromProgram) {
        if (i.orderNumber == orderNumber) {
            if (i.name == "Espresso" || i.name == "CODE BREW" ||
                i.name == "Coffee float" || i.name == "Cof++" ||
                i.name == "Caramel Macchiato" || i.name == "Matcha Latte"
                || i.name == "Mocha Frappe" || i.name == "JavaChip" ||
                i.name == "C-Frappe" || i.name == "Strawberry Frappe" ||
                i.name == "Caramel Frappe" || i.name == "Cookies and Cream"
                || i.name == "JavaSip - Green Apple" || i.name == "JavaSip - Strawberry" || i.name == "JavaSip - Mango" || i.name == "JavaSip - Lemonade" || i.name == "Lemon Iced Tea") {
                file << "Name: " << i.name << " | Size: " << i.size << " | Price: " << i.price << " | Quantity: " << i.quantity << endl;
                rawProfits += (i.price * i.quantity);
            } else {
                file << "Name: " << i.name << " | Price: " << i.price << " | Quantity: " << i.quantity << endl;
                rawProfits += (i.price * i.quantity);
            }
        }

    }
    file << "Order Number: " << orderNumber << endl;
    file << "\nTotal: " << rawProfits << endl;
    file << "--------------------------------------" << endl;
    file.close();
    this->dataFromProgram.clear(); // Clears the current data for the next order;
}

vector<Order> ReadDb::getOrderData() {
    return this->dataFromProgram;
}

void WriteDb::setDataFromProgram(vector<Order> &order) {
    this->dataFromProgram = order;
}