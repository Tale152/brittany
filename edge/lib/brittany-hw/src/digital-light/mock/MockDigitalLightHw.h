#ifndef BRITTANY_MOCK_DIGITAL_LIGHT_HW_TEMPLATE_H
#define BRITTANY_MOCK_DIGITAL_LIGHT_HW_TEMPLATE_H

#include <string>
#include "../DigitalLightHwInterface.h"

/**
 * @brief Mock class of a digital light component used only for testing purposes.
 * 
 */
class MockDigitalLightHw : public DigitalLightHwInterface {

public:

    MockDigitalLightHw(std::string id, uint8_t pin) : DigitalLightHwInterface(id, pin){ }

    void on();

    void off();

    bool isOn();

private:

    bool _isOn;
};

#endif //BRITTANY_MOCK_DIGITAL_LIGHT_HW_TEMPLATE_H