//
// Created by Florian on 28.11.17.
//

#include "EasingValue.h"

EasingValue::EasingValue(float value, float easing) {
    set(value);
    setEasing(easing);
}

void EasingValue::update() {
    auto delta = target - value;
    value += delta * easing;
}

float EasingValue::get() {
    return value;
}

void EasingValue::set(float value) {
    this->value = value;
    this->target = value;
}

void EasingValue::setEasing(float easing) {
    this->easing = easing;
}

void EasingValue::setTarget(float value) {
    this->target = value;
}

float EasingValue::getTarget() {
    return this->target;
}

float EasingValue::getEasing() {
    return this->easing;
}
