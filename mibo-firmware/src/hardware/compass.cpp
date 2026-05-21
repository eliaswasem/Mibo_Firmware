//
// Created by catgod on 20.5.2026
//

#include "compass.h"


// Define the static instance so the linker can find it
Compass Compass::compass;

Compass::Compass() {
    isInitialized = false;
}

bool Compass::begin() {
    // 1. Initialize the underlying Adafruit object (Uses default I2C address 0x3C)
    if (!qmc.begin()) {
        isInitialized = false;
        return false;
    }

    // 2. Configure the hardware using Adafruit's built-in enumerations
    qmc.setRange(QMC5883P_RANGE_8G);          // ±8 Gauss range (good for robots)
    qmc.setDataRate(QMC5883P_DATARATE_100HZ); // 100 Hz update frequency

    isInitialized = true;
    return true;
}

bool Compass::readData(float &x, float &y, float &z) {
    if (!isInitialized) return false;

    // 3. Use Adafruit's unified sensor driver structure to fetch data
    sensors_event_t event;
    qmc.getEvent(&event); // Populates the event structure with Microtesla (uT) values

    // 4. Apply hard-iron calibration offsets directly during retrieval
    x = event.magnetic.x - offsetX;
    y = event.magnetic.y - offsetY;
    z = event.magnetic.z - offsetZ;

    return true;
}

float Compass::getHeading() {
    float x, y, z;
    if (!readData(x, y, z)) return -1.0; // Return error value if sensor fails

    // 5. Calculate the yaw angle on the flat X/Y robotic plane
    float heading = atan2(y, x);
    float headingDegrees = heading * 180.0 / M_PI;

    // Normalize to 0 - 360 degrees
    if (headingDegrees < 0) {
        headingDegrees += 360.0;
    }

    return headingDegrees;
}
