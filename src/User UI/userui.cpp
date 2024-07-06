#include <iostream>
#include "MenuFunctions.cpp"

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
        cout << "Enter your choice: "; cin >> choice;

        switch(choice) {
            case 1:
                // Order
                break;
            case 2:
                // Remove Order
                break;
            case 3:
                cout << "Goodbye! Thank you for visiting Code-Brew Cafe!" << endl;
                return 0;
            default:
                cout << "Invalid Choice! Please try again." << endl;
        }
    }

}