// menu.h - Food menu (owner: C1)
#ifndef MENU_H
#define MENU_H

#include <string>

const int MENU_SIZE = 6;

struct MenuItem {
    std::string name;
    double price;   // in RM
};

// Prints the numbered menu to the screen.
void displayMenu();

// Returns the menu item for a choice from 1 to MENU_SIZE.
MenuItem getMenuItem(int choice);

#endif
