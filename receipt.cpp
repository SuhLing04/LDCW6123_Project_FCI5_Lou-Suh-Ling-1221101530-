// receipt.cpp - Order receipt (owner: C1)
#include "receipt.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Prints one line of the receipt: label on the left, amount on the right.
static void printLine(const string& label, double amount) {
    cout << left << setw(28) << label
         << right << "RM " << setw(8) << fixed << setprecision(2) << amount << "\n";
}

void displayReceipt(const vector<OrderItem>& items,
                    const Charges& charges,
                    const string& promoMessage) {
    cout << "\n==========================================\n";
    cout << "               YOUR RECEIPT\n";
    cout << "==========================================\n";

    for (size_t i = 0; i < items.size(); i++) {
        string label = to_string(items[i].quantity) + " x " + items[i].name;
        printLine(label, items[i].price * items[i].quantity);
    }

    cout << "------------------------------------------\n";
    printLine("Food subtotal", charges.subtotal);
    printLine("Delivery fee", charges.deliveryFee);
    if (charges.surcharge > 0.0) {
        printLine("Peak/rain surcharge", charges.surcharge);
    }
    printLine("Service fee (5%)", charges.serviceFee);
    if (charges.discount > 0.0) {
        printLine("Promo discount", -charges.discount);
    }
    cout << "------------------------------------------\n";
    printLine("TOTAL", charges.total);
    cout << "==========================================\n";
    cout << promoMessage << "\n";
    cout << "Estimated delivery time: " << charges.etaMinutes << " minutes\n";
}
