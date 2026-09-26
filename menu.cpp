// menu.cpp - Food menu 
#include "menu.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Menu data. Change the names and prices to match your own research (docs/menu-data.md).
static const MenuItem MENU[MENU_SIZE] = {
    {"Nasi Lemak Ayam",     9.50},
    {"Char Kuey Teow",      8.00},
    {"Roti Canai (2 pcs)",  3.50},
    {"Chicken Rice",        8.50},
    {"Mee Goreng Mamak",    7.50},
    {"Teh Tarik",           2.50}
};

void displayMenu() {
    cout << "\n------------- MENU -------------\n";
    for (int i = 0; i < MENU_SIZE; i++) {
        cout << "  " << (i + 1) << ". "
             << left << setw(24) << MENU[i].name
             << "RM " << fixed << setprecision(2) << MENU[i].price << "\n";
    }
    cout << "--------------------------------\n";
}

// Menu is shown to users as 1-6, but the array is indexed from 0,
// so choice-1 converts the user's number to the correct array position.
MenuItem getMenuItem(int choice) {
    return MENU[choice - 1];
}
