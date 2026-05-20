//
// Created by elias on 20.05.26.
//

#pragma once
#include "protocol.h"
#include <cstddef>

class PacketEncoder {
private:
    static uint8_t m_sendBuffer[258];

public:
    static size_t encode(Packet cmd, const void* payloadData = nullptr, size_t payloadSize = 0);
    static const uint8_t* getBuffer();
};
