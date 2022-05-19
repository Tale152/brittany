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

#ifndef MOCK_HUMIDITY_SENSOR_HW_H
#define MOCK_HUMIDITY_SENSOR_HW_H

#include "hw/interfaces/sensors/HumiditySensorHwInterface.h"
#include "util.h"

#define MOCK_MAX_HUMIDITY 100

/**
 * @brief Mock Implementation of a humidity sensor hw.
 */
class MockHumiditySensorHw : public HumiditySensorHwInterface {

public:

    /**
     * @brief Construct a new MockHumiditySensorHw object.
     * 
     * @param id the hw id.
     */
    MockHumiditySensorHw(std::string id) : HumiditySensorHwInterface(id) { };

    std::optional<float> humidity() {
        return std::optional<float>(random(0, MOCK_MAX_HUMIDITY));
    }

};
#endif //MOCK_HUMIDITY_SENSOR_HW_H
