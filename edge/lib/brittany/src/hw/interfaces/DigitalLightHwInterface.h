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

#ifndef BRITTANY_DIGITAL_LIGHT_HW_INTERFACE_H
#define BRITTANY_DIGITAL_LIGHT_HW_INTERFACE_H

#include <string>
#include "../ComponentHw.h"
#include "../feature/OnePin.h"
#include "../feature/Switchable.h"

/**
 * @brief An interface to create a component that represent a digital light.
 */
class DigitalLightHwInterface : public ComponentHw, public Switchable {

public:

    /**
     * @brief Construct a new Digital Light Hw Interface object.
     * 
     * @param id the unique id of the component.
     */
    DigitalLightHwInterface(std::string id) :
        ComponentHw(id),
        Switchable() {

    };

};

#endif //BRITTANY_DIGITAL_LIGHT_HW_INTERFACE_H