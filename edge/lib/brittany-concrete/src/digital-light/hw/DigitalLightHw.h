#ifndef BRITTANY_DIGITAL_LIGHT_HW_H
#define BRITTANY_DIGITAL_LIGHT_HW_H

#include "hw/interfaces/DigitalLightHwInterface.h"

/**
 * @brief Concrete implementation of a Digital Light component.
 * 
 */
class DigitalLightHw : public DigitalLightHwInterface {

public:

    DigitalLightHw(std::string id, uint8_t pin);

    void on();

    void off();

    bool isOn();

};
#endif //BRITTANY_DIGITAL_LIGHT_HW_H
