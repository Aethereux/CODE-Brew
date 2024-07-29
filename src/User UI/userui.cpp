#include <iostream>
#include "MenuFunctions.h"

// This is the main file where we will run the program
using namespace std;

int main () {
    OrderFunctions *order;
    while(true) {
        order = new OrderFunctions();
        order->createOrder();
        delete order;
    }
 }