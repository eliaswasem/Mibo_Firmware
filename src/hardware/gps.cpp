#include "gps.h"

TinyGPSPlus GPS::gps;

void GPS::begin() {
    Serial2.begin(9600);
}

void GPS::update() {
    while (Serial2.available() > 0) {
        gps.encode(Serial2.read());
    }
}

bool GPS::hasFix() {
    return gps.location.isValid() && gps.satellites.value() > 3;
}

uint32_t GPS::satellites() {
    return gps.satellites.value();
}

double GPS::getLat() {
    return gps.location.lat();
}

double GPS::getLng() {
    return gps.location.lng();
}

double GPS::distanceTo(double destLat, double destLng) {
    return TinyGPSPlus::distanceBetween(gps.location.lat(), gps.location.lng(), destLat, destLng);
}

double GPS::courseTo(double destLat, double destLng) {
    return TinyGPSPlus::courseTo(gps.location.lat(), gps.location.lng(), destLat, destLng);
}
