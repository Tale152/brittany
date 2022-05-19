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

#ifndef MOCK_HUMIDITY_HANDLER_H
#define MOCK_HUMIDITY_HANDLER_H

#include <string>
#include <list>
#include "operation-handler/interfaces/RetrieveValueFromComponentInterface.h"
#include "mock-humidity-sensor/hw/MockHumiditySensorHw.h"

class MockHumidityHandler : public RetrieveValueFromComponentInterface<MockHumiditySensorHw, float> {

public:

    MockHumidityHandler(std::list<MockHumiditySensorHw*> components)
        : RetrieveValueFromComponentInterface<MockHumiditySensorHw, float> ("airHumidity", components) {

    };

private:

    std::optional<float> sub_operation(MockHumiditySensorHw* hw, Json::Value args) {
        return hw-> humidity();
    }

};

#endif // MOCK_HUMIDITY_HANDLER_H