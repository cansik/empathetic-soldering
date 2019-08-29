//
// Created by Florian Bruggisser on 2019-08-29.
//

#include "Arduino.h"
#include "HeatTracker.h"

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
    Serial.println(tracker.getTemperature());
    delay(100);
}