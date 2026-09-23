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