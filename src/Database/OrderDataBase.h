#ifndef database_h
#define database_h

#include "../User UI/MenuFunctions.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Orders {
    private:
    // Private Variables
    vector<Menu> orderList;
    public:
    // Methods
    void addOrderToDatabase(Menu &order);
};


#endif