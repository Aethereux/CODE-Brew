#include <iostream>
#include "MenuFunctions.h"
#include <iomanip>
#include <conio.h>
#include <string>
// this file is where we will define the methods of the MenuFunctions class

using namespace std;


vector<Menu> Coffee = {
   {"Espresso", 100.00, 110.00},
   {"CODE BREW", 70.00, 80.00,},
   {"Coffee float", 100.00,120.00},
   {"Cof++", 100.00, 110.00},
   {"Caramel Macchiato", 100.00, 110.00},
   {"Matcha Latte", 100.00, 110.00},
   {"Back", 0.00, 0.00}
   // Add More Coffee
};

vector<Menu> Frappes = {
   {"Mocha Frappe", 130.00, 150.00},
   {"JavaChip", 150.00, 170.00},
   {"C-Frappe", 130.00, 150.00},
   {"Strawberry Frappe", 130.00, 150.00},
   {"Caramel Frappe", 130.00, 150.00},
   {"Cookies and Cream", 140.00, 160.00},
   {"Back", 0.00, 0.00}
   // Add More Frappes
};
vector<Menu> Refreshers = {
   {"JavaSip - Green Apple", 60.00, 75.00},
   {"JavaSip - Strawberry", 60.00, 75.00},
   {"JavaSip - Mango" , 60.00, 75.00},
   {"JavaSip - Lemonade", 60.00, 75.00},
   {"Lemon Iced Tea", 50.00, 60.00},
   {"Back", 0.00, 0.00}
   // Add More Refreshers
};
vector<Menu> Sandwiches {
   {"Hello World Sandwich", 100.00, 0},
   {"Compiled Ham and Cheese Sandwiches", 130.00, 0},
   {"Peanut Butter and Jelly Sandwich", 130.00, 0},
   {"Egg Sandwich", 110.00, 0},
   {"Cheesy Hotdog", 120.00, 0},
   {"Back", 0.00, 0.00}
   // Add More Sandwhiches
};
vector<Menu> Pastas {
   {"Carbonara", 150.00, 0},
   {"Spaghetti", 100.00, 0},
   {"Pesto", 130.00, 0},
   {"Truffle Pasta", 180.00, 0},
   {"Charlie Chan", 200.00, 0},
   {"Back", 0.00, 0.00}
   // Add More Pastas
};
vector<Menu> Pastries = {
   {"Cookie Croissant", 50.00, 0},
   {"Chocolate Chip Cookie Bytes", 60.00, 0},
   {"cin.namon Roll", 60.00, 0},
   {"Peanut Butter Chocolate Mousse Pie-thon", 60.00, 0},
   {"S'mores Cookies",60.00, 0},
   {"Cookie Peasant", 60.00, 0},
   {"Back", 0.00, 0.00}
   // Add More Pastries
};



void MenuFunctions::selector(int selected, string menuItems[], int size) {
    for (int i = 0; i < size; i++) {
        if (i == selected) {
            cout << ">> ";
        } else {
            cout << "   ";
        }
        cout << menuItems[i] << endl;
    }
}

void MenuFunctions::arrowKeySelection(int &selected, int size, int &ch) {
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

void MenuFunctions::order_or_TakeOut(string orderOrTakeOut) {
    const int size = 2;
    int selected = 0, ch = 0;
    string display[size] = {"Order", "Take Out"};
    string finalChoice;
    
    while (ch != 13){
        system("cls");
        cout << "Welcome to Code-Brew!" << endl;
        selector(selected, display, size);
        arrowKeySelection(selected, size, ch);
    }

    if (ch == 13) {
        switch (selected) {
            case 0:
            finalChoice = "Order";
            break;
            case 1:
            finalChoice = "Take Out";
            break;  
        }
    }

    orderOrTakeOut = finalChoice;
}

void MenuFunctions::selectCategory(string *item, string &category) {
    string finalCategoryChoice;
    int itemSize = 7;
    string *stringItem;

    int selected = 0, ch = 0;
    while (ch != 13) {
        system("cls");
        cout << "Select category: " << endl;
        selector(selected, item, itemSize);
        arrowKeySelection(selected, itemSize, ch);
    }

    if (ch == 13) { // Enter
        switch (selected) {
            case 0:
            finalCategoryChoice = "Coffee";
            break;
            case 1:
            finalCategoryChoice = "Frappes";
            break;
            case 2:
            finalCategoryChoice = "Refreshers";
            break;
            case 3:
            finalCategoryChoice = "Sandwiches";
            break;
            case 4:
            finalCategoryChoice = "Pastas";
            break;
            case 5:
            finalCategoryChoice = "Pastries";
            break;
            case 6:
            finalCategoryChoice = "Back";
            break;
        }
    }

    category = finalCategoryChoice;
}

void OrderFunctions::displayMenu(string itemCategory, string &finalItemChoice) {
    int selected = 0, ch = 0, i, k;
    int size;

    if (itemCategory == "Coffee"){
        size = Coffee.size();
        while(ch != 13) {
            system("cls");
            OrderFunctions::selector(selected, Coffee, size);
            OrderFunctions::arrowKeySelection(selected, size, ch);
        }
        if (ch == 13) {
            if (Coffee[selected].name == "Back") {
                finalItemChoice = "Back";
                return;
            }
            cout << "You selected: " << Coffee[selected].name << endl;
            finalItemChoice = Coffee[selected].name;
        }
    }

    if (itemCategory == "Frappes") {
        size = Frappes.size();
        while(ch != 13) {
            system("cls");
            cout << "Select Frappes: " << endl;
            OrderFunctions::selector(selected, Frappes, size);
            OrderFunctions::arrowKeySelection(selected, size, ch);
        }

        if (ch == 13) {
            if (Frappes[selected].name == "Back") {
                finalItemChoice = "Back";
                return;
            }
            cout << "You selected: " << Frappes[selected].name << endl;
            finalItemChoice = Frappes[selected].name;
        }
    }

    if (itemCategory == "Refreshers") {
        size = Refreshers.size();
        while(ch != 13) {
            system("cls");
            cout << "Select Refreshers: " << endl;
            OrderFunctions::selector(selected, Refreshers, size);
            OrderFunctions::arrowKeySelection(selected, size, ch);
        }

        if (ch == 13) {
            if (Refreshers[selected].name == "Back") {
                finalItemChoice = "Back";
                return;
            }
            cout << "You selected: " << Refreshers[selected].name << endl;
            finalItemChoice = Refreshers[selected].name;
        }
    }

    if (itemCategory == "Sandwiches") {
        size = Sandwiches.size();
        while(ch != 13) {
            system("cls");
            cout << "Select Sandwiches: " << endl;
            OrderFunctions::selector(selected, Sandwiches, size);
            OrderFunctions::arrowKeySelection(selected, size, ch);
        }

        if (ch == 13) {
            if (Sandwiches[selected].name == "Back") {
                finalItemChoice = "Back";
                return;
            }
            cout << "You selected: " << Sandwiches[selected].name << endl;
            finalItemChoice = Sandwiches[selected].name;
        }

    }

    if (itemCategory == "Pastas") {
        size = Pastas.size();
        while(ch != 13) {
            system("cls");
            cout << "Select Pastas: " << endl;
            OrderFunctions::selector(selected, Pastas, size);
            OrderFunctions::arrowKeySelection(selected, size, ch);
        }

        if (ch == 13) {
            if (Pastas[selected].name == "Back") {
                finalItemChoice = "Back";
                return;
            }
            cout << "You selected: " << Pastas[selected].name << endl;
            finalItemChoice = Pastas[selected].name;
        }
    }

    if (itemCategory == "Pastries") {
        size = Pastries.size();
        while(ch != 13) {
            system("cls");
            cout << "Select Pastries: " << endl;
            OrderFunctions::selector(selected, Pastries, size);
            OrderFunctions::arrowKeySelection(selected, size, ch);
        }

        if (ch == 13) {
            if (Pastries[selected].name == "Back") {
                finalItemChoice = "Back";
                return;
            }
            cout << "You selected: " << Pastries[selected].name << endl;
            finalItemChoice = Pastries[selected].name;
        }
    }

}

void OrderFunctions::selector(int selected, vector<Menu> &menuItems, int size) {
    cout << "==== " << "Tite" << " ====" << endl;
    cout << left << setw(43) << " " << setw(10) << "Medium" << setw(10) << "Large" << endl;
    for (int i = 0; i < size; i++) {
        if (i == selected) {
            if (menuItems[i].name == "Back") {
                cout << "\n=============================================\n";
            }
            cout << ">> ";
        } else {
            if (menuItems[i].name == "Back") {
                cout << "\n=============================================\n";
            }
            cout << "   ";
        }
        if (menuItems[i].name == "Back") {
            cout << left << setw(40) << menuItems[i].name << endl;
            continue;
        }
        // Display other items
        cout << left << setw(40) << menuItems[i].name
             << setw(10) << fixed << setprecision(2) << menuItems[i].medium
             << setw(10) << fixed << setprecision(2) << menuItems[i].large << endl;


    }
}

vector<double> OrderFunctions::getItemSize(vector<Menu> category, string &item) {
    vector<double> itemSize;
    for (Menu i : category) {
        if (i.name == item) {
            itemSize.push_back(i.medium);
            itemSize.push_back(i.large);
        }
    }
    return itemSize;
}

void OrderFunctions::selectorSize(int selected, vector<double> &itemSize, int size, string &chosenSize) {
    for (int i = 0; i < size+1; i++) {
        if (i == selected) {
            cout << ">> ";
        } else {
            cout << "   ";
        }
        switch (i) {
            case 0:
                cout << "Medium - " << itemSize[i] << endl;
                chosenSize = "Medium";
                break;
            case 1:
                if (itemSize[i] == 0) {
                    cout << "Back" << endl;
                    chosenSize = "Back";
                }
                cout << "Large - " << itemSize[i] << endl;
                chosenSize = "Large";
                break;
            case 2:
                cout << "Back" << endl;
                chosenSize = "Back";
                break;
        }
    }
}

void OrderFunctions::displaySize(string &item, string &itemSize) {
    int selected = 0, ch = 0, size = 0;
        if (item == "Coffee") {
            vector<double> drinkSize = getItemSize(Coffee, itemSize);
            while (ch != 13) {
                size = 2;
                system("cls");
                selectorSize(selected, drinkSize, size, itemSize);
                arrowKeySelection(selected, size, ch);

                if (ch == 13) {
                    cout << "You Selected " << itemSize << endl;
                }

            }
        }


}

