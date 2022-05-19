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

#ifndef BRITTANY_MOCK_TEMPERATURE_MODULE_H
#define BRITTANY_MOCK_TEMPERATURE_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"
#include "mock-temperature-sensor/hw/MockTemperatureSensorHw.h"
#include "mock-temperature-sensor/operation-handler/MockTemperatureHandler.h"
#include "modules/ComponentModule.h"
#include "modules/ModuleNames.h"

class MockTemperatureModule : public ComponentModule<MockTemperatureSensorHw> {

public:

    MockTemperatureModule(std::list<MockTemperatureSensorHw*> components)
    : ComponentModule<MockTemperatureSensorHw>(module_as_string(ModuleNames::Temperature), components) {
        _handlers.push_back(new MockTemperatureHandler(components));
    };

};

#endif //BRITTANY_MOCK_TEMPERATURE_MODULE_H