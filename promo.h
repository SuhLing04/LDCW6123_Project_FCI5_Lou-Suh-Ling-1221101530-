// promo.h - promo code logic (owner: C2)
#ifndef PROMO_H
#define PROMO_H

// MODULE: promo
// PURPOSE: Validates and applies promo codes to a food order,
// prompting the user again if the code is invalid or ineligible

// INPUTS:
// code: std::string, the promo code typed by the user (may be empty)
// subtotal: double, food subtotal before any discounts

// OUTPUTS:
// PromoResult struct containing:
//   valid: bool, true if a valid code was applied
//   discount: double, amount taken off in RM (0.0 if no code)
//   message: std::string, text shown to the user

#include <string>

struct PromoResult {
    bool valid;            // true if the code was applied
    double discount;       // amount taken off (RM)
    std::string message;   // text to show the user
};

// available promo codes and their rules:
// - "NEWUSER": 20% off food subtotal (max RM10)
// - "SAVE5": RM5 off if food subtotal is at least RM30

// check a promo code against the food subtotal
// empty code means "no promo" and is not an error
// alert user and prompt again if the code is invalid or not applicable
PromoResult applyPromo(const std::string& code, double subtotal);

#endif