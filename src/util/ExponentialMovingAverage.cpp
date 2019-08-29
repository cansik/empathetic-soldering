//
// Created by Florian Bruggisser on 2019-08-29.
//

#include "ExponentialMovingAverage.h"

ExponentialMovingAverage::ExponentialMovingAverage(float alpha) {
    this->alpha = alpha;
}

void ExponentialMovingAverage::update(float value) {
    if (firstValue) {
        firstValue = false;
        oldValue = value;
        return;
    }
    float newValue = oldValue + alpha * (value - oldValue);
    oldValue = newValue;
}

float ExponentialMovingAverage::getAverage() const {
    return oldValue;
}
