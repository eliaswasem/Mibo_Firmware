# ESP ↔ Teensy UART Protocol (Binary Framed Control Link)

---

# Packet Format


[START][LEN][CMD][DATA...]


| Field | Size    | Description                        |
|-------|---------|------------------------------------|
| START | 1 byte  | Fixed sync byte (0xAA)             |
| LEN   | 1 byte  | Number of data bytes               |
| CMD   | 1 byte  | Command ID                         |
| DATA  | N bytes | Payload (CMD-specific)             |

---

# Core Rules

- START is always `0xAA`
- LEN is **always** `0–255`
- LEN = number of DATA bytes
- CMD is always 1 byte
- DATA is strictly defined per CMD

---

# Commands

## SPEED

CMD: 0x01
TYPE: uint8_t
SIZE: 1 byte


Example:

AA 01 01 7D


---

## STOP

CMD: 0x02
TYPE: none
SIZE: 0 bytes


Example:

AA 00 02


---

## GOTO (lat, lon)

CMD: 0x10
TYPE: int32_t + int32_t
SIZE: 8 bytes


Example:

AA 08 10 [LAT 4B] [LON 4B]


---

# Example Packets

## SPEED = 125

AA 01 01 7D


## STOP

AA 00 02


## GOTO(lat, lon)

AA 08 10 1F 0B 5E 30 08 05 2A 00


---

# Receiver Logic (State Machine)

1. Wait for `0xAA`
2. Read `LEN`
3. Validate `LEN` (1–MAX_FRAME_SIZE)
4. Read `LEN` bytes into buffer
5. Extract `CMD = buffer[0]`
6. `DATA = buffer[1..]`
7. Dispatch by CMD

# Example Packet Sender

```cpp
const uint8_t* packet = PacketEncoder::encode(Packet::SET_SPEED, &SpeedPayload{150}, sizeof(SpeedPayload));
PacketWriter::write(packet)
```
