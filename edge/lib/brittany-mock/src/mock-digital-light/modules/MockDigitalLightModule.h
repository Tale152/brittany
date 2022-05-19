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

#ifndef BRITTANY_MOCK_DIGITAL_LIGHT_MODULE_H
#define BRITTANY_MOCK_DIGITAL_LIGHT_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"
#include "modules/ComponentModule.h"
#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "mock-digital-light/operation-handler/MockIsOnDigitalLightHandler.h"
#include "mock-digital-light/operation-handler/MockTurnOffDigitalLightHandler.h"
#include "mock-digital-light/operation-handler/MockTurnOnDigitalLightHandler.h"
#include "modules/ModuleNames.h"

class MockDigitalLightModule : public ComponentModule<MockDigitalLightHw> {

public:

    MockDigitalLightModule(std::list<MockDigitalLightHw*> components)
    : ComponentModule<MockDigitalLightHw>(module_as_string(ModuleNames::Light), components) {
        _handlers.push_back(new MockIsOnDigitalLightHandler(components));
        _handlers.push_back(new MockTurnOnDigitalLightHandler(components));  
        _handlers.push_back(new MockTurnOffDigitalLightHandler(components));
    };

};

#endif //BRITTANY_MOCK_DIGITAL_LIGHT_MODULE_H