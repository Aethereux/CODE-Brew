#ifndef menu_functions_h
#define menu_functions_h
#include <iostream>
#include <string>
#include <vector>
#include <map>
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
    string diningOption;
    int orderNumber;
    string name;
    string size;
    double price;
    int quantity;
    Order(string n, string s, double p, int q) : name(n), size(s), price (p), quantity(q){}
};


class MenuFunctions {
    public:
    // Public Variables
    void selectCategory(string *item, string &category);
    void selector(int selected, string menuItems[], int size);
    void arrowKeySelection(int &selected, int size, int &ch);
    void order_or_TakeOut(string &orderOrTakeOut);

};

class OrderFunctions : MenuFunctions {
    private:
    string categoryItems[8] = {"Coffee", "Frappes", "Refreshers", "Sandwiches", "Pastas", "Pastries","View Cart", "Back"};
    string order_or_takeout, category, itemOrder, itemSize;
    int quantity;
    vector<Order> orderList; // Main array
    public:
    void displayTotal();
    void checkOut();
    void addToCart(string name, string size, double price, int &quantity);
    void deleteFromCart();
    void displayCart();
    void createOrder();
    void addQuantity();
    vector<double> getItemPrice(vector<Menu> &category, string &item);
    void displayMenu(string &itemCategory, string &finalItemChoice);
    void selector(int &selected, vector<Menu> &menuItems, int size);
    void selectorCheckout(int &selected, string options[], int size);
    void selectorDeleteCart(int &selected, vector<Order> &temp, int size);
    void selectorSizeBeverages(int &selected, vector<double> &itemSize, int size, string &chosenSize);
    void selectorQuantity(int &selected);
    void selectorSizeFoods(int selected, int size, string &chosenSize);
    void arrowKeySelectionQuantity(int &selected, int size, int &ch);
    void displaySize(string &item, string &itemSize, string &itemCategory);
    double getPrice(string item, string itemSize);
    void saveOrderToDb();
};

#endif