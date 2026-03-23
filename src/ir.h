//
// Created by elias on 23.03.26.
//

#ifndef ROBO_FIRMWARE_IR_H
#define ROBO_FIRMWARE_IR_H

#include <Arduino.h>

#define IR_F   1
#define IR_R   2
#define IR_B   4
#define IR_L   5

#define IR_MIN 20
#define IR_MAX 300

void handle_ir();

#endif //ROBO_FIRMWARE_IR_H