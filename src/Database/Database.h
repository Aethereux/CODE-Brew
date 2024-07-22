//
// Created by Eux on 19/07/2024.
//

#ifndef CODE_BREW_DATABASE_H
#define CODE_BREW_DATABASE_H

#include <iostream>
#include "MenuFunctions.h"

class Database {
protected:
    char *userProfile = getenv("USERPROFILE");
    string absoluteRawFilePath = string(userProfile) + "\\Documents\\rawOrders.txt";
    string absolutePath = string(userProfile) + "\\Documents\\orders.txt";
    vector<Order> dataFromProgram;
};

#endif //CODE_BREW_DATABASE_H
