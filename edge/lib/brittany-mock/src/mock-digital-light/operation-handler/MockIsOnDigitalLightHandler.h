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

#ifndef BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
#define BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/components/IsOnSwitchableHandler.h"
#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "operation-handler/OperationHandlerResult.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"
#include <optional>

class MockIsOnDigitalLightHandler: public IsOnSwitchableHandler<MockDigitalLightHw> {

public:

    MockIsOnDigitalLightHandler(std::list<MockDigitalLightHw*> components)
        : IsOnSwitchableHandler<MockDigitalLightHw>("isOn", components) {
    };
};

#endif //BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
