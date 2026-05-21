//
// Created by elias on 20.05.26.
//

#pragma once

#include <cstdint>
#include <cstddef>
#include <esp_now.h>

class ESPNowController {
    static constexpr uint8_t ESP_MAC_ADDRESS[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // TODO: Add actual mac address
    static constexpr uint8_t WIFI_CHANNEL = 1;

    static constexpr uint8_t WIFI_ENABLE = 3; // RF switch power control
    static constexpr uint8_t WIFI_ANT_CONFIG = 14; // Antenna selection pin (HIGH = external, LOW = internal)

    public:
        static void init();
        static void send(const uint8_t *data, size_t len);
        static void onDataReceive(const esp_now_recv_info_t *recvInfo, const uint8_t *data, int len);
};
