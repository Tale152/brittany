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

#ifndef BRITTANY_DHT22_SENSOR_HW_H
#define BRITTANY_DHT22_SENSOR_HW_H

#include "hw/interfaces/TempHumHwInterface.h"
#include <string>
#include <DHT.h>
#include <DHT_U.h>
#include <optional>
#include <Adafruit_Sensor.h>

/**
 * @brief Concrete implementation of a DHT22 component.
 * 
 */
class DHT22SensorHw : public TempHumHwInterface {

public:

    /**
     * @brief Construct a new DHT22SensorHw object.
     * 
     * @param id the hw id.
     * @param pin the data pin of the DHT22.
     */
    DHT22SensorHw(std::string id, uint8_t pin);

    std::optional<float> temperatureCelsius();

    std::optional<float> temperatureKelvin();

    std::optional<float> temperatureFahrenheit();

    std::optional<float> humidity();

private:

    DHT dht;

};
#endif //BRITTANY_DHT22_SENSOR_HW_H
