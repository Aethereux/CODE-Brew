#include <iostream>
#include "MenuFunctions.h"
#include <iostream>

// this file is where we will define the methods of the MenuFunctions class

using namespace std;

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


void MenuFunctions::displayMenu() {
    cout << "Coffee" << endl;
    for (Menu item : Coffee) {
        cout << item.name << " " << item.price << " PHP"<< endl;
    }
    cout << "Frappes" << endl;
    for (Menu item : Frappes) {
        cout << item.name << " " << item.price << " PHP"<< endl;
    }
    cout << "Refreshers" << endl;
    for (Menu item : Refreshers) {
        cout << item.name << " " << item.price << " PHP" << endl;
    }
    cout << "Sandwhiches" << endl;
    for (Menu item : Sandwhiches) {
        cout << item.name << " " << item.price << " PHP" << endl;
    }
    cout << "Pastas" << endl;
    for (Menu item : Pastas) {
        cout << item.name << " " << item.price << " PHP" << endl;
    }
    cout << "Pastries" << endl;
    for (Menu item : Pastries) {
        cout << item.name << " " << item.price << " PHP" << endl;
    }
}