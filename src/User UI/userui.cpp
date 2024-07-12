#include <iostream>
#include "MenuFunctions.h"
#include <conio.h>

// This is the main file where we will run the program
using namespace std;

void displayMenu(int selected, string menuItems[], int size) {
    for (int i = 0; i < size; i++) {
        if (i == selected) {
            cout << ">> ";
        } else {
            cout << "   ";
        }
        cout << menuItems[i] << endl;
    }
}


void arrowKeySelection(int &selected, int size, int &ch) {
    ch = getch();
            if (ch == 224) {  // Arrow keys start with 224
                switch (getch()) {
                    case 72:  // Up arrow
                        selected = (selected - 1 + size) % size;
                        break;
                    case 80:  // Down arrow
                        selected = (selected + 1) % size;
                        break;
                }
            }
}

int main () {
    int choice, ch;
    int selected = 0;
    const int size = 5, foodSize = 6;

    string menuItems[size] = {"1. Order", "2. Redeem Voucher", "3. Remove Order", "4. Checkout", "5. Exit"};
    string foodItems[foodSize] = {"1. Coffee", "2. Frappes", "3. Refreshers", "4. Sandwiches", "5. Pastas", "6. Pastries"};

    MenuFunctions menu;

    while(true) {
        system("cls");
        cout << "Hello! Welcome to Code-Brew Cafe!" << endl;
        cout << "What Would you like today?" << endl;
        displayMenu(selected, menuItems, size);

        arrowKeySelection(selected, size, ch);
        
        if (ch == 13) {  // Enter key
            switch(selected) {
                case 0:
                    // Order
                    int foodSelection = 0;
                    cout << "Please Choose from the Following: ";
                    displayMenu(foodSelection, foodItems, foodSize);
                    arrowKeySelection(foodSelection, size, ch);

                    if (ch == 13) {
                        switch (foodSelection) {
                        case 0:
                            // A function to call to display Coffee Menu
                            break;
                        case 1:
                            // A Function to call to display Frappes Menu
                            break;
                        case 2:
                            // A function to call to display Refreshers Menu
                            break;
                        case 3:
                            // A function to call to dispaly Sandwiches Menu
                            break;
                        case 4:
                            // A function to call to display pastas Menu
                            break;
                        case 5:
                            // A Function to call to display pastries menu
                            break;
                        }
                    }
                    system("pause");
                    break;
                case 1:
                    // Redeem Voucher
                    cout << "Voucher Redeemed!" << endl;
                    system("pause");
                    break;
                case 2:
                    // Remove Order
                    cout << "Remove Order selected." << endl;
                    system("pause");
                    break;
                case 3:
                    // Checkout
                    cout << "Checkout selected." << endl;
                    system("pause");
                    break;
                case 4:
                    // Exit
                    cout << "Exiting..." << endl;
                    return 0;
            }
            break;
        }
    }


 }
