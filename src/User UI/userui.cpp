#include <iostream>
#include "MenuFunctions.h"
#include <conio.h>

// This is the main file where we will run the program
using namespace std;
int main () {
    OrderFunctions *order;
    // Infinite loop to
    // To do:
    /*
     * void displayCart();
     * void deleteFromCart(int index);
     *
     * View Cart
     * */
    order = new OrderFunctions();
    order->createOrder();

        system("pause");

 }

