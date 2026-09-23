// promo.h - promo code logic (owner: C2)
#ifndef PROMO_H
#define PROMO_H

#include <string>

struct PromoResult {
    bool valid;            // true if the code was applied
    double discount;       // amount taken off (RM)
    std::string message;   // text to show the user
};