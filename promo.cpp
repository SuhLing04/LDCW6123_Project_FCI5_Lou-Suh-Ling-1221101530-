// promo.cpp - Promo code logic (owner: C2)

// Winston model link: promo codes and discounts are how platforms pushed
// DIFFUSION (getting many users to adopt the service quickly)

#include "promo.h"
#include <cctype>
#include <cmath>

using namespace std;

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

    string code = normalise(rawCode);

    if (code.empty()) {
        result.message = "No promo code used.";
    } else if (code == "NEWUSER") {
        double discount = round(subtotal * 0.20 * 100.0) / 100.0;   // 20% off, in whole cents
        if (discount > 10.0) {
            discount = 10.0;                    // capped at RM10
        }
        result.valid = true;
        result.discount = discount;
        result.message = "NEWUSER applied: 20% off (max RM10).";
    } else if (code == "SAVE5") {
        if (subtotal >= 30.0) {
            result.valid = true;
            result.discount = 5.0;
            result.message = "SAVE5 applied: RM5 off.";
        } else {
            result.message = "SAVE5 needs a minimum food total of RM30.";
        }
    } else {
        result.message = "Promo code '" + code + "' is not valid.";
    }

    return result;
}