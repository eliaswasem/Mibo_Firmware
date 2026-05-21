//
// Created by elias on 20.05.26.
//

#pragma once
#include "protocol.h"
#include <cstdint>

class PacketHandler {
    enum class RxState {
        WAIT_START,
        READ_LEN,
        READ_CMD,
        READ_PAYLOAD
    };

    static uint8_t m_payloadBuffer[256];
    static RxState m_rxState;
    static uint8_t m_bytesToRead;
    static uint8_t m_bytesRead;
    static Packet m_currentCmd;

public:
    static void parseByte(uint8_t byte);
};
