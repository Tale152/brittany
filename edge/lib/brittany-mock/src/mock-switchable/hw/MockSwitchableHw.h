#ifndef MOCK_SWITCHABLE_HW_H
#define MOCK_SWITCHABLE_HW_H

#include <string>
#include "hw/interfaces/actuators/SwitchableActuatorHwInterface.h"

/**
 * @brief Represent a MockHw that can be turned on and off.
 */
class MockSwitchableHw : public SwitchableActuatorHwInterface {

public:

    /**
     * @brief Construct a new Mock Switchable Hw object.
     * 
     * @param id the id of the hw.
     */
    MockSwitchableHw(std::string id) : SwitchableActuatorHwInterface(id) { 
        _isOn = false;
    };

    void on() {
        _isOn = true;
    }

    void off() {
        _isOn = false;
    }

    bool isOn() {
        return _isOn;
    }

private:

    bool _isOn;

};

#endif //MOCK_SWITCHABLE_HW_H
