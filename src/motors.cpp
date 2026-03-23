//
// Created by elias on 23.03.26.
//

#include "motors.h"

#include <Arduino.h>
#include <esp32-hal-gpio.h>

void init_motors() {
    pinMode(MOTOR_FL_1, OUTPUT);
    pinMode(MOTOR_FL_2, OUTPUT);
    pinMode(MOTOR_FR_1, OUTPUT);
    pinMode(MOTOR_FR_2, OUTPUT);
    pinMode(MOTOR_BL_1, OUTPUT);
    pinMode(MOTOR_BL_2, OUTPUT);
    pinMode(MOTOR_BR_1, OUTPUT);
    pinMode(MOTOR_BR_2, OUTPUT);
}

void drive_forward() {}
void drive_right() {}
void drive_backwards() {}
void drive_left() {}

void stop_motors() {
    digitalWrite(MOTOR_FL_1, LOW); digitalWrite(MOTOR_FL_2, LOW);
    digitalWrite(MOTOR_FR_1, LOW); digitalWrite(MOTOR_FR_2, LOW);
    digitalWrite(MOTOR_BL_1, LOW); digitalWrite(MOTOR_BL_2, LOW);
    digitalWrite(MOTOR_BR_1, LOW); digitalWrite(MOTOR_BR_2, LOW);
}


