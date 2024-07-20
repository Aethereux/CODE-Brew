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
    int orderNumber;
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
    void selector(int selected, string menuItems[], int size);
    void arrowKeySelection(int &selected, int size, int &ch);
    void order_or_TakeOut(string orderOrTakeOut);

};

class OrderFunctions : MenuFunctions {
    private:
    string categoryItems[8] = {"Coffee", "Frappes", "Refreshers", "Sandwiches", "Pastas", "Pastries","View Cart", "Back"};
    string order_or_takeout, category, itemOrder, itemSize;
    int quantity;
    vector<Order> orderList;
    public:

    void displayTotal();
    vector<Order> getOrderList();
    void addToCart(string name, string size, double price, int &quantity);
    void deleteFromCart(int index);
    void displayCart();
    void createOrder();
    void addQuantity();
    vector<double> getItemPrice(vector<Menu> category, string &item);
    void displayMenu(string itemCategory, string &finalItemChoice);
    void selector(int selected, vector<Menu> &menuItems, int size);
    void selectorSizeBeverages(int selected, vector<double> &itemSize, int size, string &chosenSize);
    void selectorSizeFoods(int selected, vector<double> &itemSize, int size, string &chosenSize);
    void displaySize(string &item, string &itemSize, string &itemCategory);
    double getPrice(string item, string itemSize);

    void saveOrderToDb();
};

extern vector<Menu> Coffee;
extern vector<Menu> Frappes;
extern vector<Menu> Refreshers;
extern vector<Menu> Sandwiches;
extern vector<Menu> Pastas;
extern vector<Menu> Pastries;

extern map<string, vector<Menu>> itemCategoryMap;
extern map<string, vector<Menu>> categoryMap;



#endif