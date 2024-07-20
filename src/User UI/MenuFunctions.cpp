#include <iostream>
#include "MenuFunctions.h"
#include "Database.h"
#include "ReadDb.h"
#include "WriteDb.h"
#include <iomanip>
#include <conio.h>
#include <string>
#include <map>
#include <windows.h>
// this file is where we will define the methods of the MenuFunctions class

using namespace std;




vector<Menu> Coffee = {
        {"CODE BREW", 70.00, 80.00,},
        {"Espresso ", 100.00, 110.00,},
        {"Coffee float", 100.00,120.00},
        {"Cof++", 100.00, 110.00},
        {"Caramel Macchiato", 100.00, 110.00},
        {"Matcha Latte", 100.00, 110.00},
        {"View Cart", 0.00, 0.00},
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
        {"View Cart", 0.00, 0.00},
        {"Back", 0.00, 0.00}
        // Add More Frappes
};
vector<Menu> Refreshers = {
        {"JavaSip - Green Apple", 60.00, 75.00},
        {"JavaSip - Strawberry", 60.00, 75.00},
        {"JavaSip - Mango" , 60.00, 75.00},
        {"JavaSip - Lemonade", 60.00, 75.00},
        {"Lemon Iced Tea", 50.00, 60.00},
        {"View Cart", 0.00, 0.00},
        {"Back", 0.00, 0.00}
        // Add More Refreshers
};
vector<Menu> Sandwiches {
        {"Hello World Sandwich", 100.00, 0},
        {"Compiled Ham and Cheese Sandwiches", 130.00, 0},
        {"Peanut Butter and Jelly Sandwich", 130.00, 0},
        {"Egg Sandwich", 110.00, 0},
        {"Cheesy Hotdog", 120.00, 0},
        {"View Cart", 0.00, 0.00},
        {"Back", 0.00, 0.00}
        // Add More Sandwhiches
};
vector<Menu> Pastas {
        {"Carbonara", 150.00, 0},
        {"Spaghetti", 100.00, 0},
        {"Pesto", 130.00, 0},
        {"Truffle Pasta", 180.00, 0},
        {"Charlie Chan", 200.00, 0},
        {"View Cart", 0.00, 0.00},
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
        {"View Cart", 0.00, 0.00},
        {"Back", 0.00, 0.00}
        // Add More Pastries
};

map<string, vector<Menu>> itemCategoryMap = {
        {"Espresso", Coffee},
        {"CODE BREW", Coffee},
        {"Coffee float", Coffee},
        {"Cof++", Coffee},
        {"Caramel Macchiato", Coffee},
        {"Matcha Latte", Coffee},

        {"Mocha Frappe", Frappes},
        {"JavaChip", Frappes},
        {"C-Frappe", Frappes},
        {"Strawberry Frappe", Frappes},
        {"Caramel Frappe", Frappes},
        {"Cookies and Cream", Frappes},

        {"JavaSip - Green Apple", Refreshers},
        {"JavaSip - Strawberry", Refreshers},
        {"JavaSip - Mango", Refreshers},
        {"JavaSip - Lemonade", Refreshers},
        {"Lemon Iced Tea", Refreshers},

        {"Hello World Sandwich", Sandwiches},
        {"Compiled Ham and Cheese Sandwiches", Sandwiches},
        {"Peanut Butter and Jelly Sandwich", Sandwiches},
        {"Egg Sandwich", Sandwiches},
        {"Cheesy Hotdog", Sandwiches},

        {"Carbonara", Pastas},
        {"Spaghetti", Pastas},
        {"Pesto", Pastas},
        {"Truffle Pasta", Pastas},
        {"Charlie Chan", Pastas},

        {"Cookie Croissant", Pastries},
        {"Chocolate Chip Cookie Bytes", Pastries},
        {"cin.namon Roll", Pastries},
        {"Peanut Butter Chocolate Mousse Pie-thon", Pastries},
        {"S'mores Cookies", Pastries},
        {"Cookie Peasant", Pastries}
};


map<string, vector<Menu>> categoryMap = {
        {"COFFEE", Coffee},
        {"FRAPPES", Frappes},
        {"REFRESHERS", Refreshers},
        {"SANDWICHES", Sandwiches},
        {"PASTAS", Pastas},
        {"PASTRIES", Pastries}
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
    int itemSize = 8;

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
                finalCategoryChoice = "COFFEE";
                break;
            case 1:
                finalCategoryChoice = "FRAPPES";
                break;
            case 2:
                finalCategoryChoice = "REFRESHERS";
                break;
            case 3:
                finalCategoryChoice = "SANDWICHES";
                break;
            case 4:
                finalCategoryChoice = "PASTAS";
                break;
            case 5:
                finalCategoryChoice = "PASTRIES";
                break;
            case 6:
                finalCategoryChoice = "View Cart";
                break;
            case 7:
                finalCategoryChoice = "Back";
                break;

        }
    }

    category = finalCategoryChoice;
}

void OrderFunctions::displayMenu(string itemCategory, string &finalItemChoice) {
    int selected = 0, ch = 0;
    int size;
    auto it = categoryMap.find(itemCategory);
    if (it != categoryMap.end()) {
        size = it->second.size();
        while (ch != 13) {
            system("cls");
            cout << "                            " << it->first << "                           " << endl;
            cout << "-------------------------------------------------------------";
            selector(selected, it->second, size);
            arrowKeySelection(selected, size, ch);
        }

        if (ch == 13) {
            if (it->second[selected].name == "View Cart") {
                finalItemChoice = "View Cart";
                return;
            }

            if (it->second[selected].name == "Back") {
                finalItemChoice = "Back";
                return;
            }
            cout << "You Selected: " << it->second[selected].name << endl;
            finalItemChoice = it->second[selected].name;
            system("pause");
        }
    }
}

void OrderFunctions::selector(int selected, vector<Menu> &menuItems, int size) {
    bool isLargePriceZero;
    for (int i = 0; i < size; i++) {
        if (menuItems[i].large == 0) {
            isLargePriceZero = true;
        } else {
            isLargePriceZero = false;
            break;
        }
    }
    // Eto ung mga border lines sa foods
    if (isLargePriceZero) {
        cout << left << setw(35) << " " << setw(10) << " " << endl;
    } else {
        cout << "\n|" << left << setw(42.5) << " " << setw(10) << "Medium" << setw(10) << "Large  |" <<endl;
        cout<<"-------------------------------------------------------------"<<endl;
    }

    for (int i = 0; i < size; i++) {

        if (i == selected) {
            if (menuItems[i].name == "View Cart") {
                cout << "                                                            |";
                cout << "\n-------------------------------------------------------------\n";
            }
            cout << ">> ";
        } else {
            if (menuItems[i].name == "View Cart") {
                cout << "                                                            |";
                cout << "\n-------------------------------------------------------------\n";
            }
            cout << "   ";
        }

        if (menuItems[i].name == "Back" || menuItems[i].name == "View Cart") {
            cout << left << setw(40) << menuItems[i].name << endl;
            continue;
        }

        // Dito ata ung sa mga Foods
        if (menuItems[i].large == 0) {
            cout << left << setw(49) << menuItems[i].name
                 << setw(8) << fixed << setprecision(2) << menuItems[i].medium << "|" << endl;
            continue;
        } else {
            // Eto ung mga Drinks
            cout << left << setw(40) << menuItems[i].name
                 << setw(10) << fixed << setprecision(2) << menuItems[i].medium
                 << setw(7) << fixed << setprecision(2) << menuItems[i].large  << "|" << endl;
        }
    }
}



vector<double> OrderFunctions::getItemPrice(vector<Menu> category, string &item) {
    vector<double> itemSize;
    for (Menu &i : category) { // For Items that has two sizes
        if (item == "Espresso" || item == "CODE BREW" || item == "Coffee float" || item == "Cof++" || item == "Caramel Macchiato" || item == "Matcha Latte"
            || item == "Mocha Frappe" || item == "JavaChip" || item == "C-Frappe" || item == "Strawberry Frappe" || item == "Caramel Frappe" || item == "Cookies and Cream"
            || item == "JavaSip - Green Apple" || item == "JavaSip - Strawberry" || item == "JavaSip - Mango" || item == "JavaSip - Lemonade" || item == "Lemon Iced Tea") {
            itemSize.push_back(i.medium);
            itemSize.push_back(i.large);
            itemSize.push_back(0);
        } else { // For items that only have one size
            itemSize.push_back(i.medium);
            itemSize.push_back(0);
        }

    }
    return itemSize;
}

void OrderFunctions::selectorSizeFoods(int selected, vector<double> &itemPrice, int size, string &chosenSize) {
    string tempSize; // Temporary variable to hold the current selection
    for (int i = 0; i < size; i++) {
        if (i == selected) {
            cout << ">> ";
        } else {
            cout << "   ";
        }
        if (i < itemPrice.size() && itemPrice[i] == 0.00) {
            cout << "Back" << endl;
            if (i == selected) tempSize = "Back";
            break;
        } else {
            switch (i) {
                case 0:
                    cout << itemPrice[i] << " PHP" << endl;
                    if (i == selected) tempSize = "Medium";
                    break;
                default:
                    cout << "Back" << endl;
                    if (i == selected) tempSize = "Back";
                    break;
            }
        }
        cout << "----------------------|" << endl;
    }
    cout << "----------------------|" << endl;
    chosenSize = tempSize;
}

void OrderFunctions::selectorSizeBeverages(int selected, vector<double> &itemPrice, int size, string &chosenSize) {
    string tempSize; // Temporary variable to hold the current selection
    for (int i = 0; i < size; i++) {
        if (i == selected) {
            cout << ">> ";
        } else {
            cout << "   ";
        }
        if (i < itemPrice.size() && itemPrice[i] == 0.00) {
            cout << "Back" << endl;
            if (i == selected) tempSize = "Back";
            break;
        } else {
            switch (i) {
                case 0:
                    cout << "Medium - " << itemPrice[i] << endl;
                    if (i == selected) tempSize = "Medium";
                    break;
                case 1:
                    if(itemPrice[i] == 0) break;
                    cout << "Large - " << itemPrice[i] << endl;
                    if (i == selected) tempSize = "Large";
                    break;
                default:
                    cout << "Back" << endl;
                    if (i == selected) tempSize = "Back";
                    break;
            }
        }
    }
    chosenSize = tempSize;
}

void OrderFunctions::displaySize(string &item, string &itemSize, string &itemCategory) {
    int selected = 0, ch = 0, size = 0;
    auto it = itemCategoryMap.find(item);
    if (it != itemCategoryMap.end()) {
        vector<double> itemPrice = getItemPrice(it->second, item);
        if (itemCategory == "SANDWICHES" || itemCategory == "PASTAS" || itemCategory == "PASTRIES") {
            size = 2;
        } else {
            size = 3;
        }
        while (ch != 13) {
            system("cls");
            if(itemCategory == "SANDWICHES" || itemCategory == "PASTAS" || itemCategory == "PASTRIES")
                selectorSizeFoods(selected, itemPrice, size, itemSize);
            else
                selectorSizeBeverages(selected, itemPrice, size, itemSize);

            arrowKeySelection(selected, size, ch);
            if (ch == 13) {
                if (itemSize == "Back") {
                    return;
                }
            }
        }
    }
}

void OrderFunctions::addToCart(string name, string size, double price, int &quantity) {
    price = getPrice(name, size);
    Order newOrder(name,size,price,quantity);

    //adds the order to the vector
    orderList.push_back(newOrder);

    //display an affirmation that item has been added to cart
    cout<<"Item Successfully Added to Cart!" << endl;

    auto it = itemCategoryMap.find(name);
    if (it != itemCategoryMap.end()) {
        if (it->first == "Espresso" || it->first == "CODE BREW" || it->first  == "Coffee float" || it->first  == "Cof++" || it->first  == "Caramel Macchiato" || it->first  == "Matcha Latte"
            || it->first  == "Mocha Frappe" || it->first  == "JavaChip" || it->first  == "C-Frappe" || it->first  == "Strawberry Frappe" || it->first  == "Caramel Frappe" || it->first  == "Cookies and Cream"
            || it->first  == "JavaSip - Green Apple" || it->first  == "JavaSip - Strawberry" || it->first  == "JavaSip - Mango" || it->first  == "JavaSip - Lemonade" || it->first  == "Lemon Iced Tea") {
            cout<<"Item Added: "<<name<<",Size: "<<size<<",Price: "<<price<<",Quantity: "<<quantity<<endl;
        } else
            cout<<"Item Added: "<<name<<",Price: "<<price<<",Quantity: "<<quantity<<endl;
    }
    system("pause");
}

void OrderFunctions::deleteFromCart(int index) {
    // Code
    string name = orderList[index].name;
    string size = orderList[index].size;
    double price = orderList[index].price;
    int quantity = orderList[index].quantity;

    // deletes item from order vector
    orderList.erase(orderList.begin() + index);

    //confirm deletion of order
    cout<<"Item has been Deleted from Cart."<<endl;
    cout<<"Item Deleted: "<<name<<", Size"<<size<<", Price: "<<price<<", Quantity: "<<quantity<<endl;
}

void OrderFunctions::displayCart() {
    // Code
    system("cls");
    if (orderList.begin() == orderList.end()) {
        cout << "Cart is Empty" << endl;
        return;
    }
        for (int i = 0; i < orderList.size(); i++) {
            cout << "Item: " << orderList[i].name << endl;
            if (orderList[i].name == "Espresso" || orderList[i].name == "CODE BREW" ||
                orderList[i].name == "Coffee float" || orderList[i].name == "Cof++" ||
                orderList[i].name == "Caramel Macchiato" || orderList[i].name == "Matcha Latte"
                || orderList[i].name == "Mocha Frappe" || orderList[i].name == "JavaChip" ||
                orderList[i].name == "C-Frappe" || orderList[i].name == "Strawberry Frappe" ||
                orderList[i].name == "Caramel Frappe" || orderList[i].name == "Cookies and Cream"
                || orderList[i].name == "JavaSip - Green Apple" || orderList[i].name == "JavaSip - Strawberry" ||
                orderList[i].name == "JavaSip - Mango" || orderList[i].name == "JavaSip - Lemonade" || orderList[i].name == "Lemon Iced Tea") {

                cout << "Size: " << orderList[i].size << endl;
            }

            cout << "Price: " << orderList[i].price << endl;
            cout << "Quantity: " << orderList[i].quantity << endl;
            cout << "-----------------------------------" << endl;
        }
}
    void OrderFunctions::addQuantity() {
        cout << "\nEnter the quantity: ";
        cin >> this->quantity;

    if (quantity >= 1 && quantity <= 20) {
        cout << "Quantity: " << quantity << endl;
        return;
    }

    if (quantity < 1 || quantity > 20) {
        cout << "Invalid quantity. Please enter a valid quantity." << endl;
        addQuantity(); // Recursion????????????????????????????
    }
}

void OrderFunctions::createOrder() {
    static char choice = ' ';
    if (choice == ' ')
        order_or_TakeOut(this->order_or_takeout);

    selectCategory(this->categoryItems, this->category);
    if(this->category == "Back")
        createOrder(); // recursion

    if (this->category == "View Cart") {
        displayCart();
        cout << endl << system("pause");
        createOrder(); // recursion
    }


    displayMenu(this->category, this->itemOrder);
    if (this->itemOrder == "View Cart") {
        displayCart();
        cout << endl << system("pause");
        createOrder(); // recursion
        return;
    }

    // A loop that will run until the user selects anything other than "Back"
    while (this->itemOrder == "Back") {
        selectCategory(this->categoryItems, this->category);
        while (this->category == "Back") {
            order_or_TakeOut(this->order_or_takeout);
            selectCategory(this->categoryItems, this->category);
        }
        displayMenu(this->category, this->itemOrder);
            if(this->itemOrder == "View Cart") {
                displayCart();
                cout << endl << system("pause");
                createOrder(); // recursion
            }
    }

    displaySize(this->itemOrder, this->itemSize, this->category);
        while (this->itemSize == "Back") {
            displayMenu(this->category, this->itemOrder);

                // This is just a loop back don't pay too much attention to this and think how it works
                while (this->itemOrder == "Back") {
                    selectCategory(this->categoryItems, this->category);
                    while (this->category == "Back") {
                        order_or_TakeOut(this->order_or_takeout);
                        selectCategory(this->categoryItems, this->category);
                    }
                    displayMenu(this->category, this->itemOrder);
                    if(this->itemOrder == "View Cart") {
                        displayCart();
                        cout << endl << system("pause");
                        createOrder(); // recursion
                    }
                }

            if (this->itemOrder == "View Cart") {
                displayCart();
                cout << endl << system("pause");
                createOrder(); // recursion
            }

            displaySize(this->itemOrder, this->itemSize, this->category);
        }
    addQuantity();

    cout << "\nAdd To Cart? (Y/N): "; cin >> choice;
    if (choice == 'N' || choice == 'n') {
        createOrder(); // recursion
    }

    addToCart(this->itemOrder, this->itemSize, 0, this->quantity);
    // After adding to cart, ask user if they want to add more items or checkout
    // Function to call checkout
    // Function to call to display the Orders and the total and the order number for the customer

    createOrder();
}

double OrderFunctions::getPrice(string item, string size) {
    auto it = itemCategoryMap.find(item);
    if (it != itemCategoryMap.end()) {
        vector<double> itemPrice = getItemPrice(it->second, item);
        if (size == "Medium") {
            return itemPrice[0];
        } else if (size == "Large") {
            return itemPrice[1];
        }
    }
    return 0;
}
