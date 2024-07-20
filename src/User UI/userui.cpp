#include <iostream>
#include "MenuFunctions.h"

// This is the main file where we will run the program
using namespace std;
int main () {
    OrderFunctions *order;
    char choice;
    while(true) {
        order = new OrderFunctions();
        order->createOrder();
        cout << "Would you like to order again? (Y/N)" << endl;
        cin >> choice;
        if (tolower(choice) == 'n') {
            order->saveOrderToDb();
            continue;
        }
    }
 }

