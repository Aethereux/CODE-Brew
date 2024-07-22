#include <iostream>
#include "MenuFunctions.h"
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
        {"Espresso", 100.00, 110.00,},
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

void OrderFunctions::selectorCheckout(int &selected, string options[], int size) {
    for (int i = 0; i < size; i++) {
        if (i == selected) {
            cout << ">> ";
        } else {
            cout << "   ";
        }
        cout << options[i] << endl;
    }
}

void OrderFunctions::selectorDeleteCart(int &selected, vector<Order> &temp, int size) {
    double Total_Price;
    for (int i = 0; i < size; i++) {
        if (temp[i].name == "Cancel") {
            continue; // Skip the Cancel entry in the main loop
        }

        if (i == selected) {
            cout << "|>> ";
        } else {
            cout << "|   ";
        }
        if (temp[i].name == "Espresso" || temp[i].name == "CODE BREW" ||
            temp[i].name == "Coffee float" || temp[i].name == "Cof++" ||
            temp[i].name == "Caramel Macchiato" || temp[i].name == "Matcha Latte" ||
            temp[i].name == "Mocha Frappe" || temp[i].name == "JavaChip" ||
            temp[i].name == "C-Frappe" || temp[i].name == "Strawberry Frappe" ||
            temp[i].name == "Caramel Frappe" || temp[i].name == "Cookies and Cream" ||
            temp[i].name == "JavaSip - Green Apple" || temp[i].name == "JavaSip - Strawberry" ||
            temp[i].name == "JavaSip - Mango" || temp[i].name == "JavaSip - Lemonade" ||
            temp[i].name == "Lemon Iced Tea") {
            cout << left << setw(40) << temp[i].name << setw(20) << temp[i].size << setw(23) << temp[i].price << setw(22)
                 << temp[i].quantity;
        } else {
            cout << left << setw(60) << temp[i].name << setw(23) << temp[i].price << setw(22) << temp[i].quantity;
        }
        Total_Price = temp[i].price * temp[i].quantity;
        cout << setprecision(2) << setw(10) << Total_Price << "|" << endl;
    }
    cout << "|                                                                                                                      |\n";
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    //Cancel button
    for (int i = 0; i < size; i++) {
        if (temp[i].name == "Cancel") {
            if (i == selected) {
                cout << " >> ";
            } else {
                cout << "   ";
            }
            cout << "Cancel" << endl;
        }
    }
}


void MenuFunctions::selector(int selected, string menuItems[], int size) {
    for (int i = 0; i < size; i++) { // dito rin un e
        if (i == selected) {
            if (menuItems[i] == "View Cart") {
                cout << "====================================================\n";
                cout << ">> ";
            } else if (menuItems[i] == "Back") {
                cout << ">> ";
            } else
                cout << "| >> ";
        } else {
            if (menuItems[i] == "View Cart") {
                cout << "====================================================\n";
                cout << "   ";
            } else if (menuItems[i] == "Back") {
                cout << "   ";
            } else
            cout << "|   ";
        }
        cout << menuItems[i] << endl;
    }
}

void OrderFunctions::selectorQuantity(int &selected) {
    cout << "-----------------------------------\n";
    cout << "|   Quantity:  |\t " << selected <<"\t  |\n";
    cout << "-----------------------------------\n";
    cout << " + Arrow Up to Increase Quantity\n";
    cout << " - Arrow Down to Decrease Quantity\n";

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
void OrderFunctions::arrowKeySelectionQuantity(int &selected, int size, int &ch) {
    ch = getch();
    if (ch == 224) {  // Arrow keys start with 224
        switch (getch()) {
            case 72:  // Up arrow
                selected = (selected + 1 + size) % size;
                break;
            case 80:  // Down arrow
            if (selected == 0) {
                selected = 1;
            }
                selected = (selected - 1) % size;
                break;
        }
    }
}

void MenuFunctions::order_or_TakeOut(string &orderOrTakeOut) {
    const int size = 2;
    int selected = 0, ch = 0;
    string display[size] = {"Dine-In", "Take-Out"};
    while (ch != 13){
        system("cls");
        cout<<"+==============================================+"<<endl;
        cout<<"|                  CODE BREW                   |"<<endl;
        cout<<"+==============================================+"<<endl;
        cout<<"| Welcome to Code Brew! Select Ordering Option |"<<endl;
        selector(selected, display, size);
        cout<<"------------------------------------------------" << endl;
        arrowKeySelection(selected, size, ch);
    }

    if (ch == 13) {
        switch (selected) {
            case 0:
                orderOrTakeOut = display[0];
                break;
            case 1:
                orderOrTakeOut = display[1];
                break;
        }
    }
}

void MenuFunctions::selectCategory(string *item, string &category) {
    string finalCategoryChoice;
    int itemSize = 8;

    int selected = 0, ch = 0;
    while (ch != 13) {
        system("cls");
        cout << "======== What Would You Like To Have Today? ========" << endl;
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


void OrderFunctions::displayMenu(string &itemCategory, string &finalItemChoice) {
    int selected = 0, ch = 0;
    int size;
    auto it = categoryMap.find(itemCategory);
    if (it != categoryMap.end()) {
        size = it->second.size();
        while (ch != 13) {
            system("cls");
            cout << "-------------------------------------------------------------" << endl;
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
            finalItemChoice = it->second[selected].name;
        }
    }
}

void OrderFunctions::selector(int &selected, vector<Menu> &menuItems, int size) {
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
    }

    for (int i = 0; i < size; i++) {
        if (i == selected) {
            if (menuItems[i].name == "View Cart") {
                cout << "-------------------------------------------------------------\n";
                cout << ">> ";
            } else if (menuItems[i].name == "Back") {
                cout << ">> ";
            } else
                cout << "| >> ";
        } else {
            if (menuItems[i].name == "View Cart") {
                cout << "-------------------------------------------------------------\n";
                cout << "   ";
            } else if (menuItems[i].name == "Back") {
                cout << "   ";
            } else
                cout << "|   ";
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
            cout << left << setw(39) << menuItems[i].name
                 << setw(10) << fixed << setprecision(2) << menuItems[i].medium
                 << setw(7) << fixed << setprecision(2) << menuItems[i].large  << "|" << endl;
        }
    }
}

vector<double> OrderFunctions::getItemPrice(vector<Menu> &category, string &item) {
    vector<double> itemSize;
    for (Menu &i : category) {
        if (item == i.name) {
            itemSize.push_back(i.medium);
            if (i.large != 0) { // If there is a large size price, add it to the vector
                itemSize.push_back(i.large);
            }
            break; // Exit the loop once the item is found
        }
    }
    return itemSize;
}

void OrderFunctions::selectorSizeFoods(int selected, int size, string &chosenSize) {
    string tempSize; // Temporary variable to hold the current selection
    for (int i = 0; i < size; i++) {
            switch (i) {
                case 0:
                    if (i == selected) tempSize = "Medium";
                    break;
                default:
                    if (i == selected) tempSize = "Back";
                    break;
            }
    }
    chosenSize = tempSize;
}


void OrderFunctions::selectorSizeBeverages(int &selected, vector<double> &itemPrice, int size, string &chosenSize) {
    string tempSize; // Temporary variable to hold the current selection
    cout<<"+======= CUSTOMIZE ORDER ========+"<<endl;
    for (int i = 0; i < size; i++) {
        if (i == selected) {
            cout << ">> ";
        } else {
            cout << "   ";
        }
        if (i < itemPrice.size() && itemPrice[i] == 0.00) {
            cout << "Back"  << endl;
            if (i == selected) tempSize = "Back";
            break;
        } else {
            switch (i) {
                case 0:
                    cout << "Medium\t\t "<<"PHP"<< itemPrice[0]  << endl;
                    if (i == selected) tempSize = "Medium";
                    break;
                case 1:
                    if(itemPrice[i] == 0) break;
                    cout << "Large\t\t "<<"PHP"<< itemPrice[1] << endl;
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
    int selected = 0, ch = 0, size;
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
            if(itemCategory == "SANDWICHES" || itemCategory == "PASTAS" || itemCategory == "PASTRIES") {
                selectorSizeFoods(selected, size, itemSize);
                return; // Don't need to display and select size for foods
            } else
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
    newOrder.diningOption = this->order_or_takeout;
    //adds the order to the vector
    orderList.push_back(newOrder);

    //display an affirmation that item has been added to cart
    cout<<"Item Successfully Added to Cart!" << endl;
    Sleep(3000);
}

void OrderFunctions::deleteFromCart() {
    // Code
    int selected = 0, ch = 0, size;
    vector<Order> temp = orderList;
    temp.push_back({"Cancel", "", 0.00, 0});
    size = temp.size();
    while (ch != 13) {
        system("cls");
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|   ITEM NAME\t\t\t\t    SIZE\t        PRICE\t\t    QUANTITY\t\t     TOTAL     |" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        selectorDeleteCart(selected, temp ,size);
        arrowKeySelection(selected, size, ch);
    }
    if (ch == 13) {
        if (temp[selected].name == "Cancel") {
            return;
        }
        orderList.erase(orderList.begin() + selected);
    }

    cout<<"Item has been Deleted from Cart."<<endl;
}

void OrderFunctions::displayCart() {
    // Code
    system("cls");
    int selected = 0, ch = 0;
    double Total_Price = 0.0, Total = 0.0;
    string selectedOption[3] = {"Remove Items From Cart", "Check-out" , "Back"};
    if (orderList.begin() == orderList.end()) {
        cout << "Cart is Empty" << endl;
        Sleep(2000);
        return;
    }
    while (ch != 13) {

        Total = 0.0;

        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|   ITEM NAME\t\t\t\t    SIZE\t        PRICE\t\t    QUANTITY\t\t     TOTAL     |" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        for (auto &i : orderList) {
            cout << "|   ";
            if (i.name == "Espresso" || i.name == "CODE BREW" ||
                i.name == "Coffee float" || i.name == "Cof++" ||
                i.name == "Caramel Macchiato" || i.name == "Matcha Latte"
                || i.name == "Mocha Frappe" || i.name == "JavaChip" ||
                i.name == "C-Frappe" || i.name == "Strawberry Frappe" ||
                i.name == "Caramel Frappe" || i.name == "Cookies and Cream"
                || i.name == "JavaSip - Green Apple" || i.name == "JavaSip - Strawberry" ||
                i.name == "JavaSip - Mango" || i.name == "JavaSip - Lemonade" || i.name == "Lemon Iced Tea") {
                cout << left << setw(40) << i.name;
                cout << setw(20)  << i.size;
            }
            else  {
                cout << left  << setw(60)  << i.name;
            }
            cout << setw(23) << i.price;
            cout << setw(22) << i.quantity;
            Total_Price = i.price * i.quantity;
            cout << setprecision(2) << setw(10) << Total_Price;
            cout << "|" << endl;
            cout << "|                                                                                                                      |\n";
            Total += Total_Price;
        }
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|                                                                                              Total Amount: " << fixed << setprecision(2) << setw(10) << Total << "|" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        selectorCheckout(selected, selectedOption, 3);
        arrowKeySelection(selected, 3, ch);
        system("cls");
    }

    if(ch == 13) {
        switch (selected) {
            case 0:
                system("cls");
                deleteFromCart();
                break;
            case 1:
                system("cls");
                displayTotal();
                checkOut();
                break;
            case 2:
                return;
        }
    }
}

void OrderFunctions::addQuantity() {
    int selected = 1, ch;
    while (ch != 13) {
        system("cls");
        selectorQuantity(selected);
        arrowKeySelectionQuantity(selected, 20, ch);
        this->quantity = selected;
    }
    if (ch == 13) {
        if (this->quantity == 0) {
            cout << "Invalid Quantity! Try Again!" << endl;
            system("pause");
            addQuantity();
            return;
        }
        this->quantity = selected;
        return;
    }
}

void OrderFunctions::createOrder() {
    bool running = true;
    while (running) {
        if (this->order_or_takeout != "Dine-In" && this->order_or_takeout != "Take-Out") {
            order_or_TakeOut(this->order_or_takeout);
            system("pause");
        }

        selectCategory(this->categoryItems, this->category);
        if (this->category == "View Cart") {
            displayCart();
            system("pause");
            continue; // Go back to the start of the loop after viewing cart
        }

        if (this->category == "Back") {
            this->order_or_takeout = ""; // reset order_or_takeout
            continue;
        } // Go back to the start of the loop

        displayMenu(this->category, this->itemOrder);
        if (this->itemOrder == "Back") continue; // Handle back

        if (this->itemOrder == "View Cart") {
            displayCart();
            continue; // Go back to the start of the loop after viewing cart
        }

        displaySize(this->itemOrder, this->itemSize, this->category);
        if (this->itemSize == "Back") continue; // Go back to item selection

        addQuantity();

        char addMore = ' ', choice;
        while(true) {
            cout<<"-----------------------------------"<<endl;
            cout << "Add Item to Cart? (Y/N): ";
            cin >> addMore;

            if(tolower(addMore) == 'n' || tolower(addMore) == 'y') {
                break; // Go back to the start of the loop
            }
            else {
                cout << "Invalid Input! Try Again!\n";
            }
        }
        if (tolower(addMore) == 'n') continue; // Go back to the start of the loop
        addToCart(this->itemOrder, this->itemSize, 0, this->quantity);

        while (true) {
            cout << "\nCheckout? (Y/N): ";
            cin >> choice;
            if (tolower(choice) == 'y' || tolower(choice) == 'n') {
                break;
            } else {
                cout << "Invalid Input! Try Again!\n" << endl;
            }
        }
        if (tolower(choice) == 'y') {
            running = false;
            displayTotal();
            checkOut();
            break;
        }
    }
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

void OrderFunctions::saveOrderToDb() {
    ReadDb readFile;
    WriteDb writeFile;

    writeFile.addOrderToDb(this->orderList); // writes the raw data to the rawOrder.txt
    readFile.readDb(); // reads the raw data from the rawOrder.txt
    vector<Order> temp;
    temp = readFile.getOrderData(); // gets the raw data from the rawOrder.txt
    writeFile.setDataFromProgram(temp); // sets the dataFromProgram variable to the pretty data
    writeFile.addDataToDb(); // writes the pretty data to the Orders.txt
}

void OrderFunctions::displayTotal() {
    // may parameter, tinanggal ko yan kanina dkase nagamit okei
    double total = 0.0;
    static int orderNumber = 0;
    system("cls");
    cout << "-----------------------------------------------------------"<< endl;
    cout << "\t \t    ORDER NUMBER  " << endl;
    cout << " \t\t         " << ++orderNumber << endl;
    cout << "-----------------------------------------------------------"<< endl;
    cout << "\t        WELCOME TO CODE BREW! " << endl;
    cout << "\t\t  1207 Makati City" << endl << endl;
    cout << "Ordering Options:  " << this->order_or_takeout << endl << endl;


    cout << "QTY\tITEM" << right<<setw(45) << "    TOTAL" << endl;
    cout << "-----------------------------------------------------------" << endl;

    for (Order &o : orderList) {
        //unique order number
        o.orderNumber = orderNumber;
        //calculates the total of each item.
        double itemTotal = o.quantity * o.price;

        // Check if the item is a special item
        if (o.name == "Espresso" || o.name == "CODE BREW" ||
            o.name == "Coffee float" || o.name == "Cof++" ||
            o.name == "Caramel Macchiato" || o.name == "Matcha Latte" ||
            o.name == "Mocha Frappe" || o.name == "JavaChip" ||
            o.name == "C-Frappe" || o.name == "Strawberry Frappe" ||
            o.name == "Caramel Frappe" || o.name == "Cookies and Cream" ||
            o.name == "JavaSip - Green Apple" || o.name == "JavaSip - Strawberry" ||
            o.name == "JavaSip - Mango" || o.name == "JavaSip - Lemonade" || o.name == "Lemon Iced Tea") {
            cout << " " << o.quantity << "\t" << left << setw(45) << (o.name + " (" + o.size + ")")
                 << fixed << setprecision(2) << itemTotal << endl;
        } else {
            cout << " " << o.quantity << "\t" << left << setw(45) << o.name
                 << fixed << setprecision(2) << itemTotal << endl;
        }
        total += itemTotal;
    }
    cout<<"\n==========================================================="<<endl;
    cout<<left<<setw(53)<<"TOTAL:  " << fixed << setprecision(2) << total << endl;
}


void OrderFunctions::checkOut() {
    cout << "\n-----------------------------------------------------------" << endl;
    cout << "PLEASE PRESENT THIS SLIP AT THE COUNTER" << endl;
    cout << "Thank You for Choosing Code Brew!" << endl;
    cout << "See You Again." << endl;
    //save order to database
    saveOrderToDb();
    orderList.clear();
    Sleep(1000);
    system("pause");
}

