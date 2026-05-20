//
// Created by elias on 20.05.26.
//

#pragma once
#include "protocol.h"
#include <cstddef>

class PacketEncoder {
    uint8_t m_sendBuffer[258]; // START(1) + LEN(1) + CMD(1) + MAX_DATA(255)
public:
    PacketEncoder() = default;
    size_t encode(Packet cmd, const void* payloadData = nullptr, size_t payloadSize = 0);

    const uint8_t* getBuffer() const;
};
