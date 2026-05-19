//
// Created by elias on 19.05.26.
//

#include "ESPController.h"
#include <ArduinoJson.h>

void ESPController::begin() {
    Serial8.begin(115200);
    while (!Serial8.available()) {
        continue;
    }
}

void ESPController::update() {
    if (Serial8.available() > 0) {
        StaticJsonDocument<256> doc;

        // Read JSON
        DeserializationError error = deserializeJson(doc, Serial8);

        // Clear bufferon error
        if (error) {
            while (Serial8.available() > 0) {
                Serial8.read();
            }
            return;
        }


        if (doc.containsKey("coords")) {
            JsonObject coords = doc["coords"];

            float lat = coords["lat"] | 0.0f;
            float lon = coords["long"] | 0.0f;

            // Call Logic
            //handleCoordinates(lat, lon);
        }
    }
}

void ESPController::send(const char* data) {
    Serial8.println(data);
}