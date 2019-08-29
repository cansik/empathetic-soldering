//
// Created by Florian Bruggisser on 2019-08-29.
//

#include "HeatTracker.h"

void HeatTracker::setup() {
    auto status = amg.begin();

    if (!status) {
        Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
    }
}

void HeatTracker::update() {
    // read pixels
    amg.readPixels(pixels);

    // find max temperature
    temperature = 0.0f;
    auto maxX = AMG88xx_PIXEL_ARRAY_SIZE / 8;
    auto maxY = AMG88xx_PIXEL_ARRAY_SIZE / 8;

    for (int i = 0; i < AMG88xx_PIXEL_ARRAY_SIZE; i++) {
        if (temperature >= pixels[i])
            continue;

        maxX = floor(i / 8);
        maxY = (i % 8);
        temperature = pixels[i];
    }

    // normalize values
    x = maxX / 8.0f;
    y = maxY / 8.0f;
}

float HeatTracker::getX() const {
    return x;
}

float HeatTracker::getY() const {
    return y;
}

float HeatTracker::getTemperature() const {
    return temperature;
}
