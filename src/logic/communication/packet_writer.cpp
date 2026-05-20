//
// Created by elias on 20.05.26.
//

#include "packet_writer.h"
#include "esp_controller.h" // Deine Hardware-Klasse
#include <Arduino.h>        // Für Serial8

void PacketWriter::write_packet(const uint8_t* buffer) {
    if (buffer != nullptr && buffer[0] == 0xAA) {
        // buffer[1] is the LEN byte
        // Total size = LEN + 1 byte (START) + 1 byte (LEN itself).
        ESPController::write(buffer, buffer[1] + 2);
    }
}
