#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

// This is the main file where we will run the program
using namespace std;


struct Menu {
    // Menu Structure
    string name;
    double medium, large;

    Menu(string n, double m, double l) : name(n), medium(m), large(l) {}
};

vector<Menu> Coffee = {
   {"Espresso", 100.00, 110.00},
   {"CODE BREW", 70.00, 80.00,},
   {"Coffee float", 100.00,120.00},
   {"Cof++", 100.00, 110.00},
   {"Caramel Macchiato", 100.00, 110.00},
   {"Matcha Latte", 100.00, 110.00},
   // Add More Coffee
};

vector<Menu> Frappes = {
   {"Mocha Frappe", 130.00, 150.00},
   {"JavaChip", 150.00, 170.00},
   {"C-Frappe", 130.00, 150.00},
   {"Strawberry Frappe", 130.00, 150.00},
   {"Caramel Frappe", 130.00, 150.00},
   {"Cookies and Cream", 140.00, 160.00}
   // Add More Frappes
};
vector<Menu> Refreshers = {
   {"JavaSip - Green Apple", 60.00, 75.00},
   {"JavaSip - Strawberry", 60.00, 75.00},
   {"JavaSip - Mango" , 60.00, 75.00},
   {"JavaSip - Lemonade", 60.00, 75.00},
   {"Lemon Iced Tea", 50.00, 60.00}
   // Add More Refreshers
};
vector<Menu> Sandwiches {
   {"Hello World Sandwich", 100.00, 0},
   {"Compiled Ham and Cheese Sandwiches", 130.00, 0},
   {"Peanut Butter and Jelly Sandwich", 130.00, 0},
   {"Egg Sandwich", 110.00, 0},
   {"Cheesy Hotdog", 120.00, 0}
   // Add More Sandwhiches
};
vector<Menu> Pastas {
   {"Carbonara", 150.00, 0},
   {"Spaghetti", 100.00, 0},
   {"Pesto", 130.00, 0},
   {"Truffle Pasta", 180.00, 0},
   {"Charlie Chan", 200.00, 0},
   // Add More Pastas
};
vector<Menu> Pastries = {
   {"Cookie Croissant", 50.00, 0},
   {"Chocolate Chip Cookie Bytes", 60.00, 0},
   {"cin.namon Roll", 60.00, 0},
   {"Peanut Butter Chocolate Mousse Pie-thon", 60.00, 0},
   {"S'mores Cookies",60.00, 0},
   {"Cookie Peasant", 60.00, 0}
   // Add More Pastries
};



struct Order {
    // Order Structure
    string name;
    string size;

    Order(string n, string s) : name(n), size(s) {}
};


void selectMenu(int selected, string menuItems[], int size) {
    for (int i = 0; i < size; i++) {
        if (i == selected) {
            cout << ">> ";
        } else {
            cout << "   ";
        }
        cout << menuItems[i] << endl;
    }
}

void selectorVector(int selected, vector<Menu> menuItems) {
    for (int i = 0; i < menuItems.size(); i++) {
        if (i == selected) {
            cout << ">> ";
        } else {
            cout << "   ";
        }
        if (menuItems[i].large != 0)
            cout << menuItems[i].name << " " << menuItems[i].medium << " PHP " << menuItems[i].large << " PHP " << endl;
        else 
            cout << menuItems[i].name << " " <<  menuItems[i].medium << " PHP" << endl;
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


class MenuFunctions {
    private:
    // Private Variables
    vector<Order> currentOrder;
    vector<Order> orders;
    public:
    // Public Variables
    void displayMenu(int input) {
        switch(input) {
        case 0:
            cout << "Coffee" << endl;
            for (Menu item : Coffee) {
                cout << item.medium << " PHP " << item.large << " PHP" << endl;
            }
            break;
        case 1:
            cout << "Frappes:" << endl;
            for (Menu item : Frappes) {
                cout << item.medium << " PHP " << item.large << " PHP" << endl;
            }
            break;
        case 2:
            cout << "Refreshers" << endl;
            for (Menu item : Refreshers) {
                cout << item.medium << " PHP " << item.large << " PHP" << endl;
            }
            break;
        case 3:
            cout << "Sandwiches" << endl;
            for (Menu item : Sandwiches) {
                cout << item.medium << " PHP" << endl;
            }
            break;
        case 4:
            cout << "Pastas" << endl;
            for (Menu item : Pastas) {
                cout << " " << item.medium << " PHP" << endl;
            }
            break;
        case 5:
            cout << "Pastries" << endl;
            for (Menu item : Pastries) {
                cout << " " << item.medium << " PHP" << endl;
            }
            break;
    }
    
    }

    void orderForm(int c, string items[], int foodSize) {
    string *item; 
    int sizeSelection = 0, ch = 0;

        while(true){
            system("cls");
            switch(c) {
            case 0:
                system("cls");
                selectorVector(sizeSelection, Coffee);
                arrowKeySelection(sizeSelection, foodSize, ch);
                break;
            case 1:
                selectorVector(sizeSelection, Frappes);
                break;
            case 2:
                selectorVector(sizeSelection, Refreshers);
                break;
            case 3: 
                selectorVector(sizeSelection, Sandwiches);
                break;
            case 4:
                selectorVector(sizeSelection, Pastas);
                break;
            case 5:
                selectorVector(sizeSelection, Pastries);
                break;
            }
            
        }
    }
    void addOrder(string &i);
    void removeOrder(string &i);

    void setOrder();
    
};

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
        selectMenu(selected, menuItems, size);

        arrowKeySelection(selected, size, ch);
        
        if (ch == 13) {  // Enter key
            switch(selected) {
                case 0:
                    // Order
                    selected = 0;
                    while(true) {
                    system("cls");
                    cout << "Please Choose from the Following:\n";
                    selectMenu(selected, foodItems, foodSize);
                    arrowKeySelection(selected, foodSize, ch);

                    if (ch == 13) {
                        switch (selected) {
                        case 0:
                        system("cls");
                            // A function to call to display Coffee Menu
                            menu.orderForm(0, foodItems, foodSize);
                            system("pause");
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
