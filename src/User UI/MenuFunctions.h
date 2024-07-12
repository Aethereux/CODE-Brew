#ifndef menu_functions_h
#define menu_functions_h
#include <iostream>
#include <vector>   
// Class Method Declarations for the feature of the project

using namespace std;

struct Menu {
    // Menu Structure
    string name;
    double medium, large;

    Menu(string n, double m, double l) : name(n), medium(m), large(l) {}
};


struct Order {
    // Order Structure
    string name;
    double price;

    Order(string n, double p) : name(n), price(p) {}
};

class MenuFunctions {
    private:
    // Private Variables
    vector<string> currentOrder;
    vector<Order> orders;
    public:
    // Public Variables
    void displayMenu();
    void orderForm();
    void addOrder(string &i);
    void removeOrder(string &i);

};

#endif