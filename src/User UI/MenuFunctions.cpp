#include <iostream>
#include "MenuFunctions.h"

// this file is where we will define the methods of the MenuFunctions class

using namespace std;


vector<Menu> Coffee = {
   {"Espresso", 100.00, 110.00},
   {"CODE BREW", 70.00, 80.00,},
   {"Coffee float", 100.00,120.00},
   {"Cof++", 100.00, 110.00},
   {"Caramel Macchiato", 100.00, 110.00},
   {"Matcha Latte", 100.00, 110.00},
   // Add More Coffee
};


vector<Menu> Frappes = {
   {"Mocha Frappe", 130.00, 150.00},
   {"JavaChip", 150.00, 170.00},
   {"C-Frappe", 130.00, 150.00},
   {"Strawberry Frappe", 130.00, 150.00},
   {"Caramel Frappe", 130.00, 150.00},
   {"Cookies and Cream", 140.00, 160.00}
   // Add More Frappes
};
vector<Menu> Refreshers = {
   {"JavaSip - Green Apple", 60.00, 75.00},
   {"JavaSip - Strawberry", 60.00, 75.00},
   {"JavaSip - Mango" , 60.00, 75.00},
   {"JavaSip - Lemonade", 60.00, 75.00},
   {"Lemon Iced Tea", 50.00, 60.00}
   // Add More Refreshers
};
vector<Menu> Sandwhiches {
   {"Hello World Sandwich", 100.00, 0},
   {"Compiled Ham and Cheese Sandwiches", 130.00, 0},
   {"Peanut Butter and Jelly Sandwich", 130.00, 0},
   {"Egg Sandwich", 110.00, 0},
   {"Cheesy Hotdog", 120.00, 0}
   // Add More Sandwhiches
};
vector<Menu> Pastas {
   {"Carbonara", 150.00, 0},
   {"Spaghetti", 100.00, 0},
   {"Pesto", 130.00, 0},
   {"Truffle Pasta", 180.00, 0},
   {"Charlie Chan", 200.00, 0},
   // Add More Pastas
};
vector<Menu> Pastries = {
   {"Cookie Croissant", 50.00, 0},
   {"Chocolate Chip Cookie Bytes", 60.00, 0},
   {"cin.namon Roll", 60.00, 0},
   {"Peanut Butter Chocolate Mousse Pie-thon", 60.00, 0},
   {"S'mores Cookies",60.00, 0},
   {"Cookie Peasant", 60.00, 0}
   // Add More Pastries
};



void MenuFunctions::displayMenu() {
    cout << "Coffee" << endl;
    for (Menu item : Coffee) {
        cout << item.name << " " << item.medium << " PHP " << item.large << " PHP" << endl;
    }
    cout << "Frappes:" << endl;
    for (Menu item : Frappes) {
        cout << item.name << " " << item.medium << " PHP " << item.large << " PHP" << endl;
    }
    cout << "Refreshers" << endl;
    for (Menu item : Refreshers) {
        cout << item.name << " " << item.medium << " PHP " << item.large << " PHP" << endl;
    }
    cout << "Sandwhiches" << endl;
    for (Menu item : Sandwhiches) {
        cout << item.name << " " << item.medium << " PHP" << endl;
    }
    cout << "Pastas" << endl;
    for (Menu item : Pastas) {
        cout << item.name << " " << item.medium << " PHP" << endl;
    }
    cout << "Pastries" << endl;
    for (Menu item : Pastries) {
        cout << item.name << " " << item.medium << " PHP" << endl;
    }
}
