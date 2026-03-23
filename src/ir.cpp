//
// Created by elias on 23.03.26.
//

#include "ir.h"
#include "motors.h"

void handle_ir() {
    int front = analogRead(IR_F);
    int right = analogRead(IR_R);
    int left = analogRead(IR_L);
    int back = analogRead(IR_B);

    if ((front < IR_MAX && front > IR_MIN) ||
        (right < IR_MAX && right > IR_MIN) ||
        (back < IR_MAX && back > IR_MIN) ||
        (left < IR_MAX && left > IR_MIN)) {

        stop_motors();
    }
}