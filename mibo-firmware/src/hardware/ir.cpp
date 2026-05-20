//
// Created by elias on 23.03.26.
//

#include "ir.h"
#include "motors.h"


void IR::init() {
    pinMode(PIN_IR_F, INPUT);
    pinMode(PIN_IR_R, INPUT);
    pinMode(PIN_IR_L, INPUT);
    pinMode(PIN_IR_B, INPUT);
}

bool IR::handle() {
    const int front = digitalReadFast(PIN_IR_F);
    const int right = digitalReadFast(PIN_IR_R);
    const int left = digitalReadFast(PIN_IR_L);
    const int back = digitalReadFast(PIN_IR_B);

    if (front || right || back || left) {
        Motors::stop();
        return true;
    }
    return false;
}