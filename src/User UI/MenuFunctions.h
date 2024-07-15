#ifndef menu_functions_h
#define menu_functions_h
#include <iostream>
#include <string>
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
    string size;

    Order(string n, string s) : name(n), size(s) {}
};

class MenuFunctions {
    private:
    bool isBack = false;
    public:
    // Public Variables
    void selectCategory(string *item, string &category);
    void selector(int selected, string menuItems[], int size);
    void arrowKeySelection(int &selected, int size, int &ch);
    void order_or_TakeOut(string orderOrTakeOut);
    
};

class OrderFunctions : MenuFunctions {
    private:

    public:
    void displayMenu(string itemCategory, string &finalItemChoice);
    void selector(int selected, vector<Menu> &menuItems, int size);
    void selectorSize(int selected, vector<double> &itemSize, int size, string &chosenSize);
    void displaySize(string &item, string &itemSize);
    vector<double> getItemSize(vector<Menu> item, string &selected);
};

extern vector<Menu> Coffee;
extern vector<Menu> Frappes;
extern vector<Menu> Refreshers;
extern vector<Menu> Sandwiches;
extern vector<Menu> Pastas;
extern vector<Menu> Pastries;



#endif