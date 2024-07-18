#include <iostream>
#include "MenuFunctions.h"
#include <conio.h>

// This is the main file where we will run the program
using namespace std;


int main () {
    int ch;
    int selected = 0;
    string categoryItems[] = {"Coffee", "Frappes", "Refreshers", "Sandwiches", "Pastas", "Pastries", "Back"};
    string order_or_takeout, category, itemOrder, itemSize;

    MenuFunctions menu;
    OrderFunctions order;

    // Infinite loop to
            menu.order_or_TakeOut(order_or_takeout);
            menu.selectCategory(categoryItems, category);

            order.displayMenu(category, itemOrder);
            order.displaySize(itemOrder, itemSize, category);





        system("pause");

 }

