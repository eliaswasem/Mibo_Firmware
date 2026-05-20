//
// Created by elias on 20.05.26.
//

#pragma once
#include "packet_handler.h"

class AppController : public PacketHandler {
    public:
        static void onPacketReceived(const RxPacket& packet);
};
