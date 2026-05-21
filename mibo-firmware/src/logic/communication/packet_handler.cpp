//
// Created by elias on 20.05.26.
//

#include "packet_handler.h"
#include "app_controller.h"

uint8_t PacketHandler::m_payloadBuffer[256] = {0};
PacketHandler::RxState PacketHandler::m_rxState = PacketHandler::RxState::WAIT_START;
uint8_t PacketHandler::m_bytesToRead = 0;
uint8_t PacketHandler::m_bytesRead = 0;
Packet PacketHandler::m_currentCmd = static_cast<Packet>(0);

void PacketHandler::parseByte(uint8_t byte) {
    switch (m_rxState) {

        case RxState::WAIT_START:
            if (byte == PROTOCOL_START) {
                m_rxState = RxState::READ_LEN;
            }
            break;

        case RxState::READ_LEN:
            m_bytesToRead = byte;
            m_bytesRead = 0;
            m_rxState = RxState::READ_CMD;
            break;

        case RxState::READ_CMD:
            m_currentCmd = static_cast<Packet>(byte);

            if (m_bytesToRead == 0) {
                RxPacket packet{m_currentCmd, nullptr, 0};

                AppController::onPacketReceived(packet);
                m_rxState = RxState::WAIT_START;
            } else {
                m_rxState = RxState::READ_PAYLOAD;
            }
            break;

        case RxState::READ_PAYLOAD:
            m_payloadBuffer[m_bytesRead++] = byte;

            if (m_bytesRead == m_bytesToRead) {
                RxPacket packet{m_currentCmd, m_payloadBuffer, m_bytesToRead};

                AppController::onPacketReceived(packet);
                m_rxState = RxState::WAIT_START;
            }
            break;
    }
}
