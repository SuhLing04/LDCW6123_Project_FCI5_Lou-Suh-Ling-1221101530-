// promo.h - promo code logic (owner: C2)
#ifndef PROMO_H
#define PROMO_H

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