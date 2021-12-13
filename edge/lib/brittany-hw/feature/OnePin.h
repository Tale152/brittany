#ifndef BRITTANY_FEATURE_ONE_PIN_H
#define BRITTANY_FEATURE_ONE_PIN_H

#include <cstdint>

class OnePin {

public:

    OnePin(uint8_t pin);

    uint8_t pin();

private:

    uint8_t _pin;

};

#endif //BRITTANY_FEATURE_ONE_PIN_H