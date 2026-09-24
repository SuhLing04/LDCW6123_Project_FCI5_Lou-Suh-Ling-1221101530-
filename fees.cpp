// fees.cpp -delivery fee, surcharge, service fee, delivery time (owner: C2)
//
// Winston model link: fee rules are where the "social sphere" pushes back
// restaurants and regulators argue about commissions and delivery fees, and riders
// depend on peak/rain pay (these numbers are examples, not real platform prices)

#include "fees.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ---- fee settings ----
static const double NEAR_LIMIT_KM    = 3.0;
static const double MID_LIMIT_KM     = 7.0;
static const double FEE_NEAR         = 3.00;   // 0 - 3 km
static const double FEE_MID          = 5.00;   // >3 - 7 km
static const double FEE_FAR          = 8.00;   // >7 km
static const double PEAK_SURCHARGE   = 2.00;
static const double RAIN_SURCHARGE   = 1.50;
static const double SERVICE_FEE_RATE = 0.05;   // 5%

double calculateDeliveryFee(double distanceKm) {
    if (distanceKm <= NEAR_LIMIT_KM) {
        return FEE_NEAR;
    } else if (distanceKm <= MID_LIMIT_KM) {
        return FEE_MID;
    } else {
        return FEE_FAR;
    }
}

double calculateSurcharge(bool isPeakHour, bool isRaining) {
    double surcharge = 0.0;
    if (isPeakHour) {
        surcharge += PEAK_SURCHARGE;
    }
    if (isRaining) {
        surcharge += RAIN_SURCHARGE;
    }
    return surcharge;
}

double calculateServiceFee(double subtotal) {
    // round the service fee to the nearest cent
    return round(subtotal * SERVICE_FEE_RATE * 100.0) / 100.0;
}

int estimateDeliveryTime(double distanceKm, bool isPeakHour, bool isRaining) {
    int minutes = 15;                                   // food preparation
    minutes += static_cast<int>(distanceKm * 3.0+0.5); // about 3 mins per km
    if (isPeakHour) minutes += 10;                      // busy restaurants/ roads
    if (isRaining)  minutes += 5;                       // slower riding
    return minutes;
}

void displayFeeGuide() {
    cout << fixed << setprecision(2);
    cout << "\n=========== HOW WE CHARGE ===========\n";
    cout << "Delivery fee:\n";
    cout << "  0.1 to " << static_cast<int>(NEAR_LIMIT_KM) << " km ........ RM " << FEE_NEAR << "\n";
    cout << "  Over " << static_cast<int>(NEAR_LIMIT_KM) << " to " << static_cast<int>(MID_LIMIT_KM) << " km ........ RM " << FEE_MID << "\n";
    cout << "  Over " << static_cast<int>(MID_LIMIT_KM) << " to " << static_cast<int>(MAX_DISTANCE_KM) << " km ....... RM " << FEE_FAR << "\n";
    cout << "Peak hour surcharge ..... RM " << PEAK_SURCHARGE << "\n";
    cout << "Rain surcharge .......... RM " << RAIN_SURCHARGE << "\n";
    cout << "Both surcharges apply when peak hour and rain are selected.\n";
    cout << "Simulation policy: peak/rain surcharges are allocated entirely to the rider.\n";
    cout << "Service fee ............. " << (SERVICE_FEE_RATE * 100) << "% of food subtotal (before discounts)\n";
    cout << "Promo codes: NEWUSER (20% off, max RM10), SAVE5 (RM5 off, min spend RM30)\n";
    cout << "=====================================\n";
}