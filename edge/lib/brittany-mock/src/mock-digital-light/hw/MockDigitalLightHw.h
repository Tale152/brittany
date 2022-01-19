#ifndef BRITTANY_MOCK_DIGITAL_LIGHT_HW_TEMPLATE_H
#define BRITTANY_MOCK_DIGITAL_LIGHT_HW_TEMPLATE_H

#include <string>
#include "hw/interfaces/DigitalLightHwInterface.h"

/**
 * @brief Mock class of a digital light component used only for testing purposes.
 * 
 */
class MockDigitalLightHw : public DigitalLightHwInterface {

public:

    MockDigitalLightHw(std::string id) : DigitalLightHwInterface(id) {
        _isOn = false;
    }

    void on() {
        _isOn = true;
    };

    void off() {
        _isOn = false;
    };

    bool isOn() {
        return _isOn;
    };

private:

    bool _isOn;
};

#endif //BRITTANY_MOCK_DIGITAL_LIGHT_HW_TEMPLATE_H