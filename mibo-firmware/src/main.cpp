#include <Arduino.h>
#include <Wire.h>

#include "esp_controller.h"
#include "motors.h"
#include "gps.h"
#include "ultrasonic.h"

void setup() {
    Wire.begin(); //SDA 18 SCL 19
    Motors::init();
    GPS::begin();
    Ultrasonic::init();
    ESPController::begin();
}

void loop() {
    GPS::update();
    ESPController::update();
}
