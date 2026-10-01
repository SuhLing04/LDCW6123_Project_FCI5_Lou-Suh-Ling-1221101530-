# Food Delivery Order Calculator

**Course:** LDCW6123 Fundamentals of Digital Competence for Programmer

**Part 2:** Interactive C++ Program

**Related technology (Part 1):** Food delivery platforms, analysed using Brian Winston's model of technological innovation

## Purpose
This program simulates the core ordering process of a food delivery platform such as GrabFood, foodpanda, or ShopeeFood.

The user can select food items from a fixed menu, enter delivery details, and receive an itemised bill with delivery fees, surcharges, discounts, a 5% service fee, and an estimated delivery time.

The program was developed as an interactive extension of the Part 1 research on food delivery platforms and their innovation life cycle using Winston's model.

## Program overview

| | |
|---|---|
| **Inputs** | Menu selection, quantity, delivery distance (km), peak hour (y/n), rain (y/n), promo code |
| **Logic** | `switch` for the main menu, `if / else if` for fee tiers and promo codes, independent `if` statements for peak-hour and rain surcharges, loops for repeated orders, and input validation |
| **Outputs** | itemised receipt, delivery fee, surcharges, 5% service fee, discount, final total, estimated delivery time, and order confirmation/cancellation |

## Main Menu
The program provides the following options:

| Option | Description |
|---|---|
| **1. Place Order** | Select food items, enter delivery details, apply a promo code, and confirm or cancel the order. |
| **2. View Menu** | Display the available food items and prices. |
| **3. View Fee Guide** | Display the delivery fee, surcharge, and service fee information. |
| **4. Exit** | Close the program. |

## Files

| File | Owner | Purpose |
|---|---|---|
| `main.cpp` | C1 | Main menu, program flow, and order process |
| `menu.h / menu.cpp` | C1 | Food menu and prices |
| `receipt.h / receipt.cpp` | C1 | Receipt generation and display |
| `fees.h / fees.cpp` | C2 | Delivery fee, surcharge, service fee, delivery time |
| `promo.h / promo.cpp` | C2 | Promo code and discount logic |
| `validation.h / validation.cpp` | C2 | Input validation and safe input reading |

## How to compile and run

```
g++ -std=c++11 -Wall -Wextra -o delivery main.cpp menu.cpp fees.cpp promo.cpp validation.cpp receipt.cpp
./delivery
```
On Windows Command Prompt, run `delivery` instead of `./delivery`.

## Promo codes for testing
- `NEWUSER`: 20% off the food total, maximum RM10
- `SAVE5`: RM5 off, food total must be at least RM30

## Team
| Member | Role |
|---|---|
| C1 - Lou Suh Ling | Part 2 (C++ Code) - Main menu, food menu, receipt |
| C2 - Yong Yi Wen | Part 2 (C++ Code) - Fees, promo codes, input validation |
| C3 - Ong Zi Xuan | Part 1 - Winston's model Innovation Life Cycle Poster |
| C4 - Wong Zhan Hui | Part 1 - Winston's model Innovation Life Cycle Poster |
| C5 - Zoey Chu | Part 1 - Winston's model Innovation Life Cycle Poster |
| C6 - Lee Wen Le | Part 1 - Winston's model Innovation Life Cycle Poster |
