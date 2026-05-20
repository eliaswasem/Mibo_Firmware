//
// Created by elias on 20.05.26.
//

#include "packet_encoder.h"
#include <cstring>

size_t PacketEncoder::encode(Packet cmd, const void* payloadData, size_t payloadSize) {
    m_sendBuffer[0] = PROTOCOL_START;
    m_sendBuffer[1] = 1 + payloadSize; // LEN: 1 Byte for CMD + N Bytes for DATA
    m_sendBuffer[2] = static_cast<uint8_t>(cmd);

    if (payloadData != nullptr && payloadSize > 0) {
        std::memcpy(&m_sendBuffer[3], payloadData, payloadSize);
    }

    return 3 + payloadSize; // return Packet size
}

const uint8_t* PacketEncoder::getBuffer() const {
    return m_sendBuffer;
}
