//
// Created by Florian Bruggisser on 2019-08-29.
//

#ifndef EMPATHETIC_SOLDERING_HEATTRACKER_H
#define EMPATHETIC_SOLDERING_HEATTRACKER_H

#include <Adafruit_AMG88xx.h>
#include <util/EasingValue.h>
#include <util/ExponentialMovingAverage.h>

class HeatTracker {

private:
    Adafruit_AMG88xx amg;
    float pixels[AMG88xx_PIXEL_ARRAY_SIZE];

    float temperature = 0;
    float x = 0.0f;
    float y = 0.0f;

    bool easingEnabled;

    EasingValue easingX = EasingValue(0.5f, 0.1f);
    EasingValue easingY = EasingValue(0.5f, 0.1f);

    ExponentialMovingAverage averageTemperature = ExponentialMovingAverage(0.1f);

    void updateEasing();

public:
    explicit HeatTracker(bool easingEnabled = false);

    void setup();

    void update();

    /**
     * Max temperature found.
     * @return Max temperature.
     */
    float getTemperature() const;

    float getAverageTemperature() const;

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

    void setEasing(float value);

    bool isEasingEnabled() const;

    void setEasingEnabled(bool easingEnabled);
};


#endif //EMPATHETIC_SOLDERING_HEATTRACKER_H
