//
// Created by elias on 20.05.26.
//

#include "packet_writer.h"
#include "esp_controller.h"

void PacketWriter::write_packet(const uint8_t* buffer) {
    // Verify the buffer pointer is valid and contains the correct magic start byte
    if (buffer != nullptr && buffer[0] == 0xAA) {

        // Extract the raw payload length from the second byte
        uint8_t payload_len = buffer[1];

        // Total size = payload length + 3 bytes header (START, LEN, CMD)
        size_t total_size = payload_len + 3;

        // Send the complete packed byte stream to the ESP32 hardware peripheral
        ESPController::write(buffer, total_size);
    }
}
