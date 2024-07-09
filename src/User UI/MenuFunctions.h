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

class MenuFunctions {
    public:
    // Public Variables
    void displayMenu();
    void orderMenu();
};

extern vector<Menu> Coffee;
extern vector<Menu> Frappes;
extern vector<Menu> Refreshers;
extern vector<Menu> Sandwhiches;
extern vector<Menu> Pastas;
extern vector<Menu> Pastries;



#endif