//
// Created by Florian Bruggisser on 2019-08-29.
//

#ifndef EMPATHETIC_SOLDERING_EXPONENTIALMOVINGAVERAGE_H
#define EMPATHETIC_SOLDERING_EXPONENTIALMOVINGAVERAGE_H


class ExponentialMovingAverage {
private:
    bool firstValue = true;
    float alpha;
    float oldValue;

public:
    explicit ExponentialMovingAverage(float alpha);

    void update(float value);

    float getAverage() const;
};


#endif //EMPATHETIC_SOLDERING_EXPONENTIALMOVINGAVERAGE_H
