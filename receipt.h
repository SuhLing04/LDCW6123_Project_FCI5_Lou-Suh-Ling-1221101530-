// receipt.h - Order receipt (owner: C1)
#ifndef RECEIPT_H
#define RECEIPT_H

#include <string>
#include <vector>

struct OrderItem {
    std::string name;
    double price;     // price of ONE item (RM)
    int quantity;
};

struct Charges {
    double subtotal;
    double deliveryFee;
    double surcharge;
    double serviceFee;
    double discount;
    double total;
    int etaMinutes;
};

// Prints a formatted receipt.
void displayReceipt(const std::vector<OrderItem>& items,
                    const Charges& charges,
                    const std::string& promoMessage);

#endif
