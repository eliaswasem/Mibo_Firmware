//
// Created by elias on 20.05.26.
//

#include "packet_handler.h"
#include "app_controller.h"

uint8_t PacketHandler::m_payloadBuffer[256] = {0};
PacketHandler::RxState PacketHandler::m_rxState = PacketHandler::RxState::WAIT_START;
uint8_t PacketHandler::m_bytesToRead = 0;
uint8_t PacketHandler::m_bytesRead = 0;

void PacketHandler::parseByte(uint8_t byte) {
    switch (m_rxState) {
        case RxState::WAIT_START:
            if (byte == PROTOCOL_START) {
                m_rxState = RxState::READ_LEN;
            }
            break;

        case RxState::READ_LEN:
            if (byte >= 1) {
                m_bytesToRead = byte;
                m_bytesRead = 0;
                m_rxState = RxState::READ_PAYLOAD;
            } else {
                m_rxState = RxState::WAIT_START;
            }
            break;

        case RxState::READ_PAYLOAD:
            m_payloadBuffer[m_bytesRead++] = byte;

            if (m_bytesRead == m_bytesToRead) {
                RxPacket packet;
                packet.cmd = static_cast<Packet>(m_payloadBuffer[0]);
                packet.data = &m_payloadBuffer[1];
                packet.dataLen = m_bytesToRead - 1;

                AppController::onPacketReceived(packet);

                m_rxState = RxState::WAIT_START;
            }
            break;
    }
}
