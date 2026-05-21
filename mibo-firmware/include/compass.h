//
// Created by catgod on 20.5.2026
//

#pragma once
#include <Arduino.h>
#include <Adafruit_QMC5883P.h> // Include the official Adafruit driver

class Compass {
private:
    Adafruit_QMC5883P qmc;     // Low-level hardware instance
    bool isInitialized;        // Internal tracking state

public:
    static Compass compass;    // Global static instance for easy robot-wide access

    // Hard-iron calibration offsets (Crucial for robot chassis interference)
    float offsetX = 0.0;
    float offsetY = 0.0;
    float offsetZ = 0.0;

    Compass();
    bool begin();
    bool readData(float &x, float &y, float &z);
    float getHeading();
};
