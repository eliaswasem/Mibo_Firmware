//
// Created by elias on 23.03.26.
//
#pragma once

#include <Arduino.h>

class IR {
	static constexpr uint8_t PIN_IR_F = 1;
	static constexpr uint8_t PIN_IR_R = 2;
	static constexpr uint8_t PIN_IR_B = 4;
	static constexpr uint8_t PIN_IR_L = 5;

    public:
        static void init();
        static bool handle();
};