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

#ifndef BRITTANY_FEATURE_TEMPERATURE_H
#define BRITTANY_FEATURE_TEMPERATURE_H

#include <optional>

/**
 * @brief Feature of a class that can return a temperature value.
 */
class Temperature {

public:

    /**
     * @return float Get the temperature using the Celsius unit. Return empty if the
     * operation fails.
     */
    virtual std::optional<float> temperatureCelsius() = 0;

    /**
     * @return float Get the temperature using the Kelvin unit. Return empty if the
     * operation fails.
     */
    virtual std::optional<float> temperatureKelvin() = 0;

    /**
     * @return float Get the temperature using the Fahrenheit unit. Return empty if the
     * operation fails.
     */
    virtual std::optional<float> temperatureFahrenheit() = 0;

public:

    static float fromCToF(float c) {
        return c * 1.8 + 32;
    };

    static float fromCToK(float c) {
        return c + 273.15;
    };

};

#endif //BRITTANY_FEATURE_TEMPERATURE_H