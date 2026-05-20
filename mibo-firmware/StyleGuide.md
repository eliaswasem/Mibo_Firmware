# Style Guide

## File names:
    lowercase_snake_case (e.g., main.cpp)

## Class names:
    PascalCase (e.g., class MotorController)

## Pin names:
    PIN_ prefix with UPPERCASE (e.g., PIN_STATUS_LED)


## Variable names:
    camelCase (e.g., currentSpeed)

## Funtion names:
    snkae_case (e.g., motor_controller)

# Example:

## Header:

```cpp
//#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

// Class names
class MotorController {
private:
    // Variable names
    inline static int currentSpeed = 0;
    inline static bool isRunning = false;

public:
    // Function names (static)
    static void init_controller();
    static void set_speed(int targetSpeed);
};

#endif // MOTOR_CONTROLLER_H
```

## File
```cpp
#include "motor_controller.h"
#include <iostream>

void MotorController::init_controller() {
    currentSpeed = 0;
    isRunning = false;
}

void MotorController::set_speed(int targetSpeed) {
    currentSpeed = targetSpeed;
    isRunning = (targetSpeed > 0);
}
```
