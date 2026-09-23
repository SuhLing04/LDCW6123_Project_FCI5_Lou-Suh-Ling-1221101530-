// validation.cpp - Safe user input helpers (owner: C2)

// Why getline + istringstream instead of cin >> number?
// If the user types letters, "cin >> number" puts cin into a fail state and the
// program can loop forever. Reading a full line and parsing it ourselves avoids that.

#include "validation.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>

using namespace std;

// read one line 
// if input has ended (e.g. Ctrl+D / Ctrl+Z), exit cleanly
static string getInputLine(const string& prompt) {
    cout << prompt;
    string line;
    if (!getline(cin, line)) {
        cout << "\nInput closed. Goodbye!\n";
        exit(0);
    }
    return line;
}

int readInt(const string& prompt, int minVal, int maxVal) {
    while (true) {
        string line = getInputLine(prompt);
        istringstream iss(line);
        int value;
        char extra;

        // MUST read a num AND have nothing left over (so "3.5" or "2abc" are rejected)
        if ((iss >> value) && !(iss >> extra)) {
            if (value >= minVal && value <= maxVal) {
                return value;
            }
            cout << "  [!] Please enter a number between "
                 << minVal << " and " << maxVal << ".\n";
        } else {
            cout << "  [!] Invalid input. Please enter a whole number.\n";
        }
    }
}

double readDouble(const string& prompt, double minVal, double maxVal) {
    while (true) {
        string line = getInputLine(prompt);
        istringstream iss(line);
        double value;
        char extra;

        if ((iss >> value) && !(iss >> extra)) {
            if (value >= minVal && value <= maxVal) {
                return value;
            }
            cout << "  [!] Please enter a number between "
                 << minVal << " and " << maxVal << ".\n";
        } else {
            cout << "  [!] Invalid input. Please enter a number (e.g. 4.5).\n";
        }
    }
}

bool readYesNo(const string& prompt) {
    while (true) {
        string line = getInputLine(prompt);
    }
}

string readLine(const string& prompt) {}