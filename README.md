# Food Delivery Order Calculator

**Course:** LDCW6123 Fundamentals of Digital Competence for Programmer
**Part 2:** Interactive C++ Program
**Related technology (Part 1):** Food delivery platforms, analysed with Winston's model

## Purpose
A console program that simulates the core of a food delivery platform. The customer
builds an order and the program calculates the fees, surcharges, discount, total price
and estimated delivery time.

## Program plan

| | |
|---|---|
| **Inputs** | Menu choice, quantity, distance (km), peak hour (y/n), rain (y/n), promo code |
| **Logic** | `switch` for the main menu, `if / else if` for fee tiers and promo codes, loops for the cart and repeated orders, input validation for every input |
| **Outputs** | Itemised receipt, total price, estimated delivery time, order confirmation |

## Link to Winston model (Part 1)

| Program feature | Winston stage |
|---|---|
| Menu and order building | Prototype / Invention: listing, ordering and payment in one app |
| Distance-based delivery fee | Diffusion: pricing that lets the service scale |
| Peak and rain surcharge | Supervening social necessity: busy urban life and bad weather drive demand |
| Promo codes | Diffusion: discounts to attract new users |
| Fee guide and clear receipt | Suppression of radical potential: pressure from regulators, restaurants and riders for fair, transparent fees |

## Files

| File | Owner | Purpose |
|---|---|---|
| `main.cpp` | C1 | Main menu (`switch`), order flow |
| `menu.h / menu.cpp` | C1 | Food menu and prices |
| `receipt.h / receipt.cpp` | C1 | Receipt printing |
| `fees.h / fees.cpp` | C2 | Delivery fee, surcharge, service fee, delivery time |
| `promo.h / promo.cpp` | C2 | Promo code logic |
| `validation.h / validation.cpp` | C2 | Safe input reading |

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
(Add member names and roles here)
