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

#ifndef BRITTANY_FEATURE_ONE_PIN_H
#define BRITTANY_FEATURE_ONE_PIN_H

#include <cstdint>

/**
 * @brief Wrapper class that contains a pin. This class is mostly used to create a ComponentHw.
 * 
 */
class OnePin {

public:

    /**
     * @brief Construct a new One Pin object.
     * 
     * @param pin the pin to encapsulate.
     */
    OnePin(uint8_t pin);

    /**
     * @brief get the pin.
     * 
     * @return uint8_t the pin.
     */
    uint8_t pin();

private:

    uint8_t _pin;

};

#endif //BRITTANY_FEATURE_ONE_PIN_H