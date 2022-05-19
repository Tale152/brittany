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

#ifndef BRITTANY_MOCK_DEHUMIDIFIER_MODULE_H
#define BRITTANY_MOCK_DEHUMIDIFIER_MODULE_H

#include <list>
#include "operation-handler/interfaces/components/TurnOffSwitchableHandler.h"
#include "operation-handler/interfaces/components/TurnOnSwitchableHandler.h"
#include "operation-handler/interfaces/components/IsOnSwitchableHandler.h"
#include "mock-switchable/hw/MockSwitchableHw.h"
#include "modules/ComponentModule.h"
#include "modules/ModuleNames.h"

class MockDehumidifierModule : public ComponentModule<MockSwitchableHw> {

public:

    MockDehumidifierModule(std::list<MockSwitchableHw*> components)
    : ComponentModule<MockSwitchableHw>(module_as_string(ModuleNames::Humidity), components) {
        _handlers.push_back(
            new TurnOnSwitchableHandler<MockSwitchableHw>(
               "dehumidifyOn",
               components
            )
        );
        _handlers.push_back(
            new TurnOffSwitchableHandler<MockSwitchableHw>(
               "dehumidifyOff",
               components
            )
        );
        _handlers.push_back(
            new IsOnSwitchableHandler<MockSwitchableHw>(
               "isDehumidifyOn",
               components
            )
        );
    };

};

#endif //BRITTANY_MOCK_DEHUMIDIFIER_MODULE_H