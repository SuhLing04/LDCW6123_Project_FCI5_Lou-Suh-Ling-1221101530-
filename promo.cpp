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
}