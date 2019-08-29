//
// Created by Florian Bruggisser on 2019-08-29.
//

#ifndef EMPATHETIC_SOLDERING_HEATTRACKER_H
#define EMPATHETIC_SOLDERING_HEATTRACKER_H

#include <Adafruit_AMG88xx.h>

class HeatTracker {

private:
    Adafruit_AMG88xx amg;
    float pixels[AMG88xx_PIXEL_ARRAY_SIZE];

    float temperature = 0;
    float x = 0;
    float y = 0;

public:
    void setup();

    void update();

    /**
     * Max temperature found.
     * @return Max temperature.
     */
    float getTemperature() const;

    /**
     * Normalized x value.
     * @return x value between 0.0 and 1.0
     */
    float getX() const;

    /**
     * Normalized y value.
     * @return y value between 0.0 and 1.0
     */
    float getY() const;
};


#endif //EMPATHETIC_SOLDERING_HEATTRACKER_H
