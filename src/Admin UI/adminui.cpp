#include <iostream>
#include "VoucherSystem.h"
#include "AdminFeatures.h"

using namespace std;

int main () {
    int choice;

    while(true) {
        cout << "Hello Admin! What would you like to do today?" << endl;
        cout << "1. Create Voucher" << endl;
        cout << "2. Remove Voucher" << endl;
        cout << "3. View Coupons" << endl;
        cout << "4. View Orders" << endl;
        cout << "5. View Statistics" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: "; cin >> choice;

        switch(choice) {
            case 1:
                // Create Voucher
                break;
            case 2:
                // Remove Voucher
                break;
            case 3:
                // View Coupons
                break;
            case 4:
                // View Orders
                break;
            case 5:
                // View Statistics
                break;
            case 6:
                cout << "Goodbye Admin!" << endl;
                return 0;
            default:
                cout << "Invalid Choice! Please try again." << endl;
        }
    }

}


