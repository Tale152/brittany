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

#ifndef BRITTANY_TEMP_HUM_SENSOR_HW_INTERFACE_H
#define BRITTANY_TEMP_HUM_SENSOR_HW_INTERFACE_H

#include <string>
#include "../ComponentHw.h"
#include "../feature/OnePin.h"
#include "../feature/Humidity.h"
#include "../feature/Temperature.h"

/**
 * @brief An interface to create a component that represents a sensor that can
 * obtain temperature(air) and humidity(air) values.
 */
class TempHumHwInterface :
    public ComponentHw,
    public OnePin,
    public Temperature,
    public Humidity {

public:

    TempHumHwInterface(std::string id, uint8_t pin) :
        ComponentHw(id),
        OnePin(pin),
        Temperature(),
        Humidity() {

    };

};

#endif //BRITTANY_TEMP_HUM_SENSOR_HW_INTERFACE_H