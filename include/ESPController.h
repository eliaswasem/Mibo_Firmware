//
// Created by elias on 19.05.26.
//

#pragma once

#include <Arduino.h>

class ESPController {


public:
    void begin();
    void update();
    void send(const char* data);

};

#endif // ESP_CONTROLLER_H
