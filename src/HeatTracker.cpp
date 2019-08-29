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
    temperature = -500.0f;
    auto maxX = AMG88xx_PIXEL_ARRAY_SIZE / 2;
    auto maxY = AMG88xx_PIXEL_ARRAY_SIZE / 2;

    for (int i = 0; i < AMG88xx_PIXEL_ARRAY_SIZE; i++) {
        if(temperature >= pixels[i])
            return;

        temperature = pixels[i];
        maxX = (int)floor(i / 8.0);
        maxY = (i % 8);
    }

    // normalize values
    x = maxX / 8.0f;
    y = maxX / 8.0f;
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
