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

void arrowKeySelection(int &selected, int size, int &ch);
void selectMenu(int selected, string menuItems[], int size);
void selectorVector(int selected, vector<Menu> menuItems);


struct Order {
    // Order Structure
    string name;
    string size;

    Order(string n, string s) : name(n), size(s) {}
};

class MenuFunctions {
    private:
    // Private Variables
    vector<Order> currentOrder;
    vector<Order> orders;
    public:
    // Public Variables
    void displayMenu(int input);
    void orderForm(int c, string items[], int foodSize);
    void addOrder(string &i);
    void removeOrder(string &i);

    void setOrder();

    void getStringItem(int c, string *itemName);
    
};

extern vector<Menu> Coffee;
extern vector<Menu> Frappes;
extern vector<Menu> Refreshers;
extern vector<Menu> Sandwiches;
extern vector<Menu> Pastas;
extern vector<Menu> Pastries;



#endif