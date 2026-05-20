//
// Created by elias on 20.05.26.
//

#include "app_controller.h"

#include "motors.h"

void AppController::onPacketReceived(const RxPacket& packet) {

    if (packet.cmd == Packet::STOP) {
        Motors::stop();
    }

    else if (packet.cmd == Packet::SPEED) {
        if (packet.dataLen == sizeof(SpeedPayload)) {
            const auto* payload = reinterpret_cast<const SpeedPayload*>(packet.data);
            Motors::set_motor_speed(payload->speed);
        }
    }

    else if (packet.cmd == Packet::GOTO) {
        if (packet.dataLen == sizeof(GotoPayload)) {
            const auto* payload = reinterpret_cast<const GotoPayload*>(packet.data);
            // Navigation::set_target(payload->lat, payload->lon);
        }
    }
}
