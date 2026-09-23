// fees.h - Delivery fee, surcharge, service fee, delivery time (owner: C2)
#ifndef FEES_H
#define FEES_H

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