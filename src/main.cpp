//
// Created by Florian Bruggisser on 2019-08-29.
//

#include "Arduino.h"
#include "HeatTracker.h"

HeatTracker tracker;

void setup() {
    Serial.begin(9600);

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

    Serial.println("------------");
    delay(3000);
}