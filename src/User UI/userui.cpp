#include <iostream>
#include "MenuFunctions.h"

// This is the main file where we will run the program
using namespace std;

int main () {
    int choice;
    MenuFunctions menu;

    while(true) {
        cout << "Hello! Welcome to Code-Brew Cafe!" << endl;
        cout << "What would you like today?" << endl;
        menu.displayMenu();
        cout << "1. Order" << endl;
        cout << "2. Remove Order" << endl;
        cout << "3. Exit" << endl;

        switch(choice) {

        }
    }

}