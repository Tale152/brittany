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

#ifndef BRITTANY_DIGITAL_LIGHT_HW_H
#define BRITTANY_DIGITAL_LIGHT_HW_H

#include "hw/interfaces/DigitalLightHwInterface.h"
#include "hw/feature/OnePin.h"

/**
 * @brief Concrete implementation of a Digital Light component.
 * 
 */
class DigitalLightHw : public DigitalLightHwInterface, public OnePin {

public:

    DigitalLightHw(std::string id, uint8_t pin);

    void on();

    void off();

    bool isOn();

};
#endif //BRITTANY_DIGITAL_LIGHT_HW_H
