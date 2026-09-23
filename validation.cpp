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
    }
}

double readDouble(const string& prompt, double minVal, double maxVal) {}

bool readYesNo(const string& prompt) {}

string readLine(const string& prompt) {}