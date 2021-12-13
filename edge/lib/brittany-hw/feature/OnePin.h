#ifndef BRITTANY_FEATURE_ONE_PIN_H
#define BRITTANY_FEATURE_ONE_PIN_H

#include <cstdint>

/**
 * @brief Wrapper class that contains a pin. This class is mostly used to create a ComponentHw.
 * 
 */
class OnePin {

public:

    /**
     * @brief Construct a new One Pin object.
     * 
     * @param pin the pin to encapsulate.
     */
    OnePin(uint8_t pin);

    /**
     * @brief get the pin.
     * 
     * @return uint8_t the pin.
     */
    uint8_t pin();

private:

    uint8_t _pin;

};

#endif //BRITTANY_FEATURE_ONE_PIN_H