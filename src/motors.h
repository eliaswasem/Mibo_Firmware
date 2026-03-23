//
// Created by elias on 23.03.26.
//

#ifndef ROBO_FIRMWARE_MOTORS_H
#define ROBO_FIRMWARE_MOTORS_H

#define MOTOR_FL_1 21
#define MOTOR_FL_2 47
#define MOTOR_FR_1 13
#define MOTOR_FR_2 14
#define MOTOR_BL_1 15
#define MOTOR_BL_2 16
#define MOTOR_BR_1 11
#define MOTOR_BR_2 12

#define SPEED_MIN 0
#define SPEED_MAX 255
#define SPEED_DEFAULT 150

void init_motors();
void drive_forward();
void drive_right();
void drive_backwards();
void drive_left();
void stop_motors();
void set_motor_speed(int speed);


#endif //ROBO_FIRMWARE_MOTORS_H