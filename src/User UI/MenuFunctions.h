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
    int quanity;

    Order(string n, string s, double p, int q) : name(n), size(s), price (p), quanity(q){}
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
    string *itemCategory;
    string order_or_takeout, category, itemOrder, itemSize;

    //stores user input of orders
    vector<Order>orders;

    public:
    OrderFunctions() {
    };
    void displayMenu(string itemCategory, string &finalItemChoice);
    void selector(int selected, vector<Menu> &menuItems, int size);
    void selectorSize(int selected, vector<double> &itemSize, int size, string &chosenSize);
    void displaySize(string &item, string &itemSize, string &itemCategory);
    vector<double> getItemPrice(vector<Menu> category, string &item);

    //function to create an order
    void addTocart (string name, string size, double price, int quanity) {
        Order newOrder(name,size,price,quanity);

        //adds the order to the vector
        orders.push_back(newOrder);

        //display an affirmation that item has been added to cart
        cout<<"Item Successfully Added to Cart!<<endl";
        cout<<"Item Added: "<<name<<",Size: "<<size<<",Price: "<<price<<",Quanity: "<<quanity<<endl;
    }

    //function to delete an order
    void deleteFromcart (string name, string size,double price, int quantity) {

    }

};

extern vector<Menu> Coffee;
extern vector<Menu> Frappes;
extern vector<Menu> Refreshers;
extern vector<Menu> Sandwiches;
extern vector<Menu> Pastas;
extern vector<Menu> Pastries;



#endif