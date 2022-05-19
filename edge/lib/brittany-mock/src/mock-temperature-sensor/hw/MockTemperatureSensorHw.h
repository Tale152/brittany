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

#ifndef MOCK_TEMPERATURE_SENSOR_HW_H
#define MOCK_TEMPERATURE_SENSOR_HW_H

#include "hw/interfaces/sensors/TemperatureSensorHwInterface.h"

#define MOCK_MAX_TEMPERATURE_CELSIUS 40

/**
 * @brief Mock Implementation of a temperature sensor hw.
 */
class MockTemperatureSensorHw : public TemperatureSensorHwInterface {

public:

    /**
     * @brief Construct a new MockTemperatureSensorHw object.
     * 
     * @param id the hw id.
     */
    MockTemperatureSensorHw(std::string id) : TemperatureSensorHwInterface(id) { };

    std::optional<float> temperatureCelsius() {
        return std::optional<float>(random(0, MOCK_MAX_TEMPERATURE_CELSIUS));
    }

    std::optional<float> temperatureKelvin() {
        std::optional<float> tempC = temperatureCelsius();
        if(tempC.has_value()){
            return std::optional(Temperature::fromCToK(tempC.value()));
        }
        return std::nullopt;
    }

    std::optional<float> temperatureFahrenheit(){
        std::optional<float> tempC = temperatureCelsius();
        if(tempC.has_value()){
            return std::optional(Temperature::fromCToF(tempC.value()));
        }
        return std::nullopt;
    }

};
#endif //MOCK_TEMPERATURE_SENSOR_HW_H
