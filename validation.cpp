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