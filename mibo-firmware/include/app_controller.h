// Created by elias on 20.05.26.
#pragma once
#include "protocol.h"

class AppController {
public:
    static void onPacketReceived(const RxPacket& packet);
};
