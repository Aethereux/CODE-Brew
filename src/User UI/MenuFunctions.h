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
    double price;
    int quantity;
    Order(string n, string s, double p, int q) : name(n), size(s), price (p), quantity(q){}
};

class MenuFunctions {
private:
public:
    // Public Variables
    void selectCategory(string *item, string &category);
    virtual void selector(int selected, string menuItems[], int size);
    virtual void arrowKeySelection(int &selected, int size, int &ch);
    virtual void order_or_TakeOut(string orderOrTakeOut);

};

class OrderFunctions : MenuFunctions {
private:
    string categoryItems[7] = {"Coffee", "Frappes", "Refreshers", "Sandwiches", "Pastas", "Pastries", "Back"};
    string order_or_takeout, category, itemOrder, itemSize;
    int quantity;
    vector<Order> orderList;
public:
    OrderFunctions() {

    };
    //function to create an order
    void createOrder();
    void addToCart(string name, string size, double price, int &quanity);
    void deleteFromCart(int index);
    void displayCart();
    void addQuantity();
    vector<double> getItemPrice(vector<Menu> category, string &item);
    void displayMenu(string itemCategory, string &finalItemChoice);
    void selector(int selected, vector<Menu> &menuItems, int size);
    void selectorSizeBeverages(int selected, vector<double> &itemSize, int size, string &chosenSize);
    void selectorSizeFoods(int selected, vector<double> &itemSize, int size, string &chosenSize);
    void displaySize(string &item, string &itemSize, string &itemCategory);
    double getPrice(string item, string size);
};

extern vector<Menu> Coffee;
extern vector<Menu> Frappes;
extern vector<Menu> Refreshers;
extern vector<Menu> Sandwiches;
extern vector<Menu> Pastas;
extern vector<Menu> Pastries;



#endif