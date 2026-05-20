//
// Created by elias on 20.05.26.
//

#include "packet_encoder.h"
#include <cstring>

// Definition of the thread-local storage buffer
thread_local uint8_t PacketEncoder::m_sendBuffer[PacketEncoder::BUFFER_SIZE] = {0};

const uint8_t* PacketEncoder::encode(Packet cmd, const void* payloadData, size_t payloadSize) {
    if (payloadSize > MAX_PAYLOAD_SIZE) {
        payloadSize = MAX_PAYLOAD_SIZE;
    }

    m_sendBuffer[0] = PROTOCOL_START;
    m_sendBuffer[1] = static_cast<uint8_t>(payloadSize);
    m_sendBuffer[2] = static_cast<uint8_t>(cmd);

    if (payloadData != nullptr && payloadSize > 0) {
        std::memcpy(&m_sendBuffer[HEADER_SIZE], payloadData, payloadSize);
    }

    return m_sendBuffer;
}
