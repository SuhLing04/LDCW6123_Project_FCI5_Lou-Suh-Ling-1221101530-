// =====================================================================
// Food Delivery Order Calculator
// Course : LDCW6123 Fundamentals of Digital Competence for Programmer
// Part 2 : Interactive C++ Program
//
// Purpose:
//   Simulates the core of a food delivery platform (like GrabFood,
//   foodpanda, ShopeeFood): the customer builds an order, and the
//   program calculates fees, surcharges, discounts, total price and
//   estimated delivery time.
//
// Link to Part 1 (Winston Model of food delivery platforms):
//   - Menu + order building ....... PROTOTYPE/INVENTION: app combines restaurant
//                                   listing, ordering and payment in one place
//   - Distance-based delivery fee . DIFFUSION: how the service is priced to scale
//   - Peak / rain surcharge ....... SUPERVENING SOCIAL NECESSITY: busy urban life
//                                   and bad weather create demand for delivery
//   - Promo codes ................. DIFFUSION: discounts to attract new users
//   - Fee guide + transparency .... SUPPRESSION OF RADICAL POTENTIAL: society
//                                   (regulators, restaurants, riders) pushes for
//                                   fair and clear fees
//
// Inputs : menu choice, quantity, distance (km), peak hour, rain, promo code
// Outputs: itemised receipt, total price, estimated delivery time
//
// Team   : C1 - main.cpp, menu, receipt   |   C2 - fees, promo, validation
// =====================================================================

#include <iostream>
#include <string>
#include <vector>

#include "menu.h"
#include "fees.h"
#include "promo.h"
#include "receipt.h"
#include "validation.h"

using namespace std;

const int MAX_QUANTITY = 20;

// Prints the main menu.
static void showMainMenu() {
    cout << "\n========================================\n";
    cout << "   FOOD DELIVERY ORDER CALCULATOR\n";
    cout << "========================================\n";
    cout << "  1. Place an order\n";
    cout << "  2. View menu\n";
    cout << "  3. View fee guide\n";
    cout << "  4. Exit\n";
    cout << "----------------------------------------\n";
}

// Prevents duplicate rows in the receipt: e.g. ordering "2x Nasi Lemak" then
// "1x Nasi Lemak" later shows as one line of "3x Nasi Lemak", not two lines.
// Adds an item to the cart. If the same item is already there, increase the quantity.
static void addToCart(vector<OrderItem>& cart, const MenuItem& item, int quantity) {
    for (size_t i = 0; i < cart.size(); i++) {
        if (cart[i].name == item.name) {
            cart[i].quantity += quantity;
            return;
        }
    }
    OrderItem newItem;
    newItem.name = item.name;
    newItem.price = item.price;
    newItem.quantity = quantity;
    cart.push_back(newItem);
}

// Adds up price * quantity for every item currently in the cart.
static double calculateSubtotal(const vector<OrderItem>& cart) {
    double subtotal = 0.0;
    for (size_t i = 0; i < cart.size(); i++) {
        subtotal += cart[i].price * cart[i].quantity;
    }
    return subtotal;
}

// Runs one full order from start to receipt.
static void placeOrder() {
    vector<OrderItem> cart;

    // ---- Step 1: build the cart ----
    bool isBuildingCart = true;
    while (isBuildingCart) {
        displayMenu();
        int choice = readInt("Choose an item (1-" + to_string(MENU_SIZE) +
                             ", or 0 to finish): ", 0, MENU_SIZE);

        if (choice == 0) {
            if (cart.empty()) {
                cout << "Your cart is empty. Order cancelled.\n";
                return;
            }
            isBuildingCart = false;
        } else {
            MenuItem item = getMenuItem(choice);
            int quantity = readInt("How many " + item.name + "? (1-" +
                                   to_string(MAX_QUANTITY) + "): ", 1, MAX_QUANTITY);
            addToCart(cart, item, quantity);
            cout << "  Added " << quantity << " x " << item.name << " to your cart.\n";
        }
    }

    // ---- Step 2: delivery details ----
    double distance = readDouble("\nDelivery distance in km (0.1-" +
                                 to_string(static_cast<int>(MAX_DISTANCE_KM)) + "): ",
                                 0.1, MAX_DISTANCE_KM);
    bool isPeak = readYesNo("Is it peak hour (lunch/dinner rush)? (y/n): ");
    bool isRain = readYesNo("Is it raining? (y/n): ");
    string promoCode = readLine("Promo code (press Enter to skip): ");

    // ---- Step 3: calculate everything ----
    // Order matters: subtotal must be known before service fee and promo discount,
    // since both are percentages/conditions based on the food subtotal.
    Charges charges;
    charges.subtotal = calculateSubtotal(cart);

    charges.deliveryFee = calculateDeliveryFee(distance);
    charges.surcharge   = calculateSurcharge(isPeak, isRain);
    charges.serviceFee  = calculateServiceFee(charges.subtotal);

    PromoResult promo = applyPromo(promoCode, charges.subtotal);
    charges.discount = promo.discount;

    charges.total = charges.subtotal + charges.deliveryFee +
                    charges.surcharge + charges.serviceFee - charges.discount;
    if (charges.total < 0.0) {
        charges.total = 0.0;
    }
    charges.etaMinutes = estimateDeliveryTime(distance, isPeak, isRain);

    // ---- Step 4: show the receipt and confirm ----
    displayReceipt(cart, charges, promo.message);

    if (readYesNo("\nConfirm this order? (y/n): ")) {
        cout << "\nOrder confirmed! Your food is on the way. Thank you!\n";
    } else {
        cout << "\nOrder cancelled. No charge was made.\n";
    }
}

int main() {
    bool running = true;

    while (running) {
        showMainMenu();
        int option = readInt("Choose an option (1-4): ", 1, 4);


        // Menu option 4 sets running = false instead of calling exit(), so any
        // cleanup code added later would still run before the program closes.
        switch (option) {
            case 1:
                placeOrder();
                break;
            case 2:
                displayMenu();
                break;
            case 3:
                displayFeeGuide();
                break;
            case 4:
                running = false;
                break;
        }
    }

    cout << "\nThank you for using the Food Delivery Order Calculator. Goodbye!\n";
    return 0;
}
