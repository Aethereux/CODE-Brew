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
    private:
    // Private Variables

    public:
    // Public Variables
    void displayMenu();
};



#endif