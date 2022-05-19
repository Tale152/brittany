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