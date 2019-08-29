//
// Created by Florian Bruggisser on 2019-08-29.
//

#include <sensor/HeatTracker.h>
#include "Arduino.h"

auto tracker = HeatTracker(true);

void setup() {
    Serial.begin(9600);

    tracker.setEasing(0.2);
    tracker.setup();
}

void loop() {
    tracker.update();

    Serial.print("X: ");
    Serial.print(tracker.getX());
    Serial.print(" Y: ");
    Serial.print(tracker.getY());
    Serial.print(" Temp: ");
    Serial.print(tracker.getTemperature());
    Serial.print(" AvTemp: ");
    Serial.println(tracker.getAverageTemperature());
    delay(100);
}