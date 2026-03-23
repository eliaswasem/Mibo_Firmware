#include <Arduino.h>

#include "ir.h"
#include "motors.h"

void setup() {
    init_motors();
}

void loop() {
    handle_ir();
}
