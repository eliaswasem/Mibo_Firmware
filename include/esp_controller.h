//
// Created by elias on 19.05.26.
//

#pragma once

#include <Arduino.h>

class ESPController {
    static constexpr uint8_t BUFFER_SIZE = 128;

public:
    static void begin();

    static void processCommand(const char *json);

    static void update();
    static void send(const char* data);

};
