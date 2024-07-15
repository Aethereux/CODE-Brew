//
// Created by Eux on 15/07/2024.
//

void displayMenu(const vector<Menu>& menu, const string& category) {
    cout << "==== " << category << " ====" << endl;
    cout << left << setw(40) << " " << setw(10) << "Medium" << setw(10) << "Large" << endl;
    cout << "---------------------------------------------" << endl;
    for (const auto& item : menu) {
        cout << left << setw(40) << item.name
             << setw(10) << fixed << setprecision(2) << item.medium
             << setw(10) << fixed << setprecision(2) << item.large
             << endl;
    }
    cout << endl;
}
