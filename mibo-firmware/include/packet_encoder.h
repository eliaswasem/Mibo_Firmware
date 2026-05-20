//
// Created by elias on 20.05.26.
//

#pragma once
#include "protocol.h"
#include <cstddef>

class PacketEncoder {
    public:
        static constexpr uint8_t PROTOCOL_START = 0xAA;
        static constexpr size_t HEADER_SIZE = 3;       // START (1B) + LEN (1B) + CMD (1B)
        static constexpr size_t MAX_PAYLOAD_SIZE = 255;
        static constexpr size_t BUFFER_SIZE = HEADER_SIZE + MAX_PAYLOAD_SIZE; // 258 Bytes total

        // Encodes the packet and returns the pointer directly to the buffer
        static const uint8_t* encode(Packet cmd, const void* payloadData, size_t payloadSize);
    private:
        uint8_t m_buffer[BUFFER_SIZE];static thread_local uint8_t m_sendBuffer[BUFFER_SIZE];
};
