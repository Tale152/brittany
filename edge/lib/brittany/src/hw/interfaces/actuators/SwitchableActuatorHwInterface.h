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

#ifndef BRITTANY_SWITCHABLE_ACTUATOR_HW_INTERFACE_H
#define BRITTANY_SWITCHABLE_ACTUATOR_HW_INTERFACE_H

#include <string>
#include "hw/ComponentHw.h"
#include "hw/feature/Switchable.h"

/**
 * @brief An interface to create a component that represent an actuator that can be turned on and off.
 */
class SwitchableActuatorHwInterface : public ComponentHw, public Switchable {

public:

    /**
     * @brief Construct a new Switchable Actuator Hw Interface object.
     * 
     * @param id 
     */
    SwitchableActuatorHwInterface(std::string id) :
        ComponentHw(id),
        Switchable() {

    };

};

#endif //BRITTANY_SWITCHABLE_ACTUATOR_HW_INTERFACE_H