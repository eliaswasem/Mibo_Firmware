//
// Created by elias on 20.05.26.
//

#include "packet_encoder.h"
#include <cstring>

uint8_t PacketEncoder::m_sendBuffer[258] = {0};

size_t PacketEncoder::encode(Packet cmd, const void* payloadData, size_t payloadSize) {
    m_sendBuffer[0] = PROTOCOL_START;
    m_sendBuffer[1] = 1 + payloadSize;
    m_sendBuffer[2] = static_cast<uint8_t>(cmd);

    if (payloadData != nullptr && payloadSize > 0) {
        std::memcpy(&m_sendBuffer[3], payloadData, payloadSize);
    }

    return 3 + payloadSize;
}

const uint8_t* PacketEncoder::getBuffer() {
    return m_sendBuffer;
}
