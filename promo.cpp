// promo.cpp - Promo code logic (owner: C2)

// Winston model link: promo codes and discounts are how platforms pushed
// DIFFUSION (getting many users to adopt the service quickly)

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