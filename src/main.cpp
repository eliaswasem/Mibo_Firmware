#include <Arduino.h>
#include <Wire.h>

#include "esp_controller.h"
#include "ir.h"
#include "motors.h"
#include "gps.h"
#include "ultrasonic.h"

void setup() {
    Wire.begin(); //SDA 18 SCL 19
    Motors::init();
    GPS::begin();
    IR::init();
    Ultrasonic::init();
    ESPController::begin();
}

void loop() {
    IR::handle();
    GPS::update();
}
