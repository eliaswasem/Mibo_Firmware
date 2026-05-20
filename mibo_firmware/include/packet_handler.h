//
// Created by elias on 20.05.26.
//

#pragma once
#include "protocol.h"

class PacketHandler {
    enum class RxState {
        WAIT_START,
        READ_LEN,
        READ_PAYLOAD
    };

    static uint8_t m_payloadBuffer[256];
    static RxState m_rxState;
    static uint8_t m_bytesToRead;
    static uint8_t m_bytesRead;

public:
    PacketHandler() = delete;

    static void parseByte(uint8_t byte);
};
