//
// Created by elias on 20.05.26.
//

#include "packet_forwarder.h"

#include "teensy_controller.h"
#include "esp_now_controller.h"

void PacketForwarder::forwardToTeensy(const uint8_t* buffer) {
    if (buffer != nullptr && buffer[0] == 0xAA) {
        size_t totalSize = buffer[1] + 3;

        TeensyController::write(buffer, totalSize);
    }
}

void PacketForwarder::forwardToEsp(const uint8_t* buffer) {
    if (buffer != nullptr && buffer[0] == 0xAA) {
        size_t totalSize = buffer[1] + 3;
        ESPNowController::send(buffer, totalSize);
    }
}
