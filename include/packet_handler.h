//
// Created by elias on 20.05.26.
//

#pragma once
#include "protocol.h"
#include <cstddef>

class PacketHandler {
private:
    enum class RxState {
        WAIT_START,
        READ_LEN,
        READ_PAYLOAD
    };

    uint8_t m_payloadBuffer[256]; // storage for CMD + DATA
    RxState m_rxState = RxState::WAIT_START;
    uint8_t m_bytesToRead = 0;
    uint8_t m_bytesRead = 0;

protected:
    virtual void onPacketReceived(const RxPacket& packet) = 0;

public:
    PacketHandler() = default;
    virtual ~PacketHandler() = default;

    void parseByte(uint8_t byte);
};
