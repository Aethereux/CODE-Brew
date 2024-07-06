#ifndef menu_functions_h
#define menu_functions_h
#include <iostream>
#include <vector>
// Class Method Declarations for the feature of the project

using namespace std;

struct Menu {
    // Menu Structure
    string name;
    double price;

    Menu(string n, double p) : name(n), price(p) {}
};

vector<Menu> Coffee = {
    {"Espresso", 50.00},
    {"Kape HAHA", 69},
    // Add More Coffee
};

vector<Menu> Frappes = {
    {"Mocha Frappe", 100.00},
    // Add More Frappes
};
vector<Menu> Refreshers = {
    {"Refresher Drink", 69.99},
    // Add More Refreshers
};
vector<Menu> Sandwhiches {
    // Add More Sandwhiches
};
vector<Menu> Pastas {
    {"Carbonara", 150.00},
    // Add More Pastas

};
vector<Menu> Pastries = {
    {"Croissant", 50.00},
    // Add More Pastries
};


class MenuFunctions {
    private:
    // Private Variables

    public:
    // Public Variables
    void displayMenu();
};



#endif