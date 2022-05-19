/* * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
