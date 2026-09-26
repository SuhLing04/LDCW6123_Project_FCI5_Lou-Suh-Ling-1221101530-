// fees.h - Delivery fee, surcharge, service fee, delivery time (owner: C2)
#ifndef FEES_H
#define FEES_H

// MODULE: fees
// PURPOSE: Calculates all delivery-related charges and estimated time

// INPUTS:
// distanceKm: double, distance in km (pre-validated within 0.1 - 20)
// isPeakHour: bool, true if order is during lunch/dinner rush
// isRaining: bool, true if raining during delivery
// subtotal: double, food subtotal before any discounts

// OUTPUTS:
// calculateDeliveryFee() -> delivery fee in RM based on distance tier
// calculateSurcharge() -> extra charge in RM for peak hour and/or rain
// calculateServiceFee() -> 5% of food subtotal, rounded to nearest cent
// estimateDeliveryTime() -> estimated delivery time in mins
// displayFeeGuide() -> displays the full fee rules to the user

const double MAX_DISTANCE_KM = 20.0;   // we do not deliver beyond this

// delivery fee based on distance (tiered)
double calculateDeliveryFee(double distanceKm);

// extra charge for peak hour and/or rain.
double calculateSurcharge(bool isPeakHour, bool isRaining);

// platform service fee (% of food subtotal)
double calculateServiceFee(double subtotal);

// estimated delivery time in mins
int estimateDeliveryTime(double distanceKm, bool isPeakHour, bool isRaining);

// prints the fee rules so users understand how they are charged
void displayFeeGuide();

#endif