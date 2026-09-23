// validation.h - Safe user input helpers (owner: C2)
#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

// keep asking until the user enters a whole number between minVal and maxVal
int readInt(const std::string& prompt, int minVal, int maxVal);

// keep asking until the user enters a number between minVal and maxVal
double readDouble(const std::string& prompt, double minVal, double maxVal);

// keep asking until the user enters y/yes or n/no
// return true for yes
bool readYesNo(const std::string& prompt);

// read a whole line of text (may be empty)
std::string readLine(const std::string& prompt);

#endif
