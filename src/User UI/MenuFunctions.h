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

class MenuFunctions {
    public:
    // Public Variables
    void displayMenu();
};

extern vector<Menu> Coffee;
extern vector<Menu> Frappes;
extern vector<Menu> Refreshers;
extern vector<Menu> Sandwhiches;
extern vector<Menu> Pastas;
extern vector<Menu> Pastries;



#endif