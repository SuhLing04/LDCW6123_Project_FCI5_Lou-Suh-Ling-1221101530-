// validation.h - Safe user input helpers (owner: C2)
#ifndef VALIDATION_H
#define VALIDATION_H

// MODULE: validation
// PURPOSE: Provides safe input reading helpers that prevent infinite
// loops and reject invalid input before it reaches other modules

// INPUTS:
//   prompt: std::string, message shown to the user
//   minVal: minimum accepted value (readInt, readDouble)
//   maxVal: maximum accepted value (readInt, readDouble)

// OUTPUTS:
//   readInt() -> int, validated whole num
//   readDouble() -> double, validated decimal num
//   readYesNo() -> bool, true for yes, false for no
//   readLine() -> std::string, any text the user typed

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
