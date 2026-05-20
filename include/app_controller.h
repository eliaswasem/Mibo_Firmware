//
// Created by elias on 20.05.26.
//

#pragma once
#include "packet_handler.h"

class AppController : public PacketHandler {
protected:
    void onPacketReceived(const RxPacket& packet) override;
};
