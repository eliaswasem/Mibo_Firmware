//
// Created by elias on 19.05.26.
//
#include "ESPController.h"
#include "ArduinoJson.h"

void ESPController::begin() {
    Serial8.begin(115200);
}

void ESPController::update() {

    static char buffer[BUFFER_SIZE];
    static uint8_t index = 0;

    while (Serial8.available()) {

        char c = Serial8.read();

        if (c == '\r') continue;

        if (c == '\n') {

            buffer[index] = '\0';
            processCommand(buffer);
            index = 0;
        }
        else {

            if (index < BUFFER_SIZE - 1) {
                buffer[index++] = c;
            }
            else {
                Serial8.println("ERR_OVERFLOW");
                index = 0;
            }
        }
    }
}

void ESPController::processCommand(const char* json) {

    JsonDocument doc;

    if (DeserializationError err = deserializeJson(doc, json)) {
        Serial8.println("ERR_JSON");
        return;
    }

    const char* cmd = doc["cmd"];

    if (!cmd) {
        Serial8.println("ERR_CMD");
        return;
    }

    if (strcmp(cmd, "goto") == 0) {
        if (!doc["lat"].is<float>() || !doc["lon"].is<float>()) {
            Serial8.println("ERR_DATA");
            return;
        }
        float lat = doc["lat"];
        float lon = doc["lon"];

        // Todo: Handle this
        return;
    }

    if (strcmp(cmd, "speed") == 0) {

        if (!doc["value"].is<float>()) {
            Serial8.println("ERR_DATA");
            return;
        }

        float v = doc["value"];

        // Todo: Handle this
        return;
    }

    if (strcmp(cmd, "stop") == 0) {

        // Todo: Handle this
        return;
    }

    Serial8.println("ERR_UNKNOWN");
}

void ESPController::send(const char* data) {
    Serial8.println(data);
}