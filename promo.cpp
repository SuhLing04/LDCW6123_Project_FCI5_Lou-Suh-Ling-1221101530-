// promo.cpp - Promo code logic (owner: C2)

// Winston model link: promo codes and discounts are how platforms pushed
// DIFFUSION (getting many users to adopt the service quickly)

// MODULE: promo
// PURPOSE: Validates and applies promo codes to a food order,
// prompting the user again if the code is invalid or ineligible

// DESIGN LOGIC (step by step):
//   1. Normalise input (uppercase, strip spaces) so "newuser" as "NEWUSER"
//   2. If code is empty, skip promo and return immediately
//   3. If code is NEWUSER, apply 20% off the food subtotal, capped at RM10
//   4. If code is SAVE5, apply RM5 off only if subtotal >= RM30
//   5. If code is unrecognised or ineligible, alert user and re-prompt
//   6. Repeat until a valid code is entered or the user skips
 
// INPUTS:
// rawCode: std::string, the promo code typed by the user (may be empty)
// subtotal: double, food subtotal before any discounts
//
// OUTPUTS:
// PromoResult struct containing:
//   valid: bool, true if a valid code was applied
//   discount: double, amount taken off in RM (0.0 if no code)
//   message: std::string, text shown to the user

#include "promo.h"
#include <cctype>
#include <cmath>
#include "validation.h"   // for readLine
#include <iostream>  

using namespace std;

// ---- promo settings ----
static const double NEWUSER_RATE    = 0.20;  // 20% off food subtotal
static const double NEWUSER_CAP     = 10.00; // max discount for NEWUSER
static const double SAVE5_MIN_SPEND = 30.00; // minimum food subtotal for SAVE5
static const double SAVE5_DISCOUNT  = 5.00;  // discount amount for SAVE5

// convert to upper case and removes spaces so "newuser" matches "NEWUSER" etc
static string normalise(const string& text) {
    string result;
    for (size_t i = 0; i < text.size(); i++) {
        unsigned char c = static_cast<unsigned char>(text[i]);
        if (!isspace(c)) {
            result += static_cast<char>(toupper(c));
        }
    }
    return result;
}

PromoResult applyPromo(const string& rawCode, double subtotal) {
    PromoResult result;
    result.valid = false;
    result.discount = 0.0;

    string code = rawCode;

    while (true) {
        string normalised = normalise(code);

        if (normalised.empty()) {
            result.message = "No promo code used.";
            return result;
        }

        if (normalised == "NEWUSER") {
            double discount = round(subtotal * NEWUSER_RATE * 100.0) / 100.0;
            if (discount > NEWUSER_CAP) {
                discount = NEWUSER_CAP;
            }
            result.valid = true;
            result.discount = discount;
            result.message = "NEWUSER applied: 20% off (max RM10).";
            return result;
        } else if (normalised == "SAVE5") {
            if (subtotal >= SAVE5_MIN_SPEND) {
                result.valid = true;
                result.discount = SAVE5_DISCOUNT;
                result.message = "SAVE5 applied: RM5 off.";
                return result;
            } else {
                cout << "  [!] SAVE5 needs a minimum food total of RM30.\n";
            }
        } else {
            cout << "  [!] Promo code '" << normalised << "' is not valid.\n";
        }

        // Invalid code: ask again
        code = readLine("Promo code (press Enter to skip): ");
    }
}