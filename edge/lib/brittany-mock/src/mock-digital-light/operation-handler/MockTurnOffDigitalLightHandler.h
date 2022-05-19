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

#ifndef BRITTANY_MOCK_TURN_OFF_DIGITAL_LIGHT_HANDLER_INTERFACE_H
#define BRITTANY_MOCK_TURN_OFF_DIGITAL_LIGHT_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include "operation-handler/interfaces/components/TurnOffSwitchableHandler.h"
#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "operation-handler/OperationHandlerResult.h"
#include "util.h"

class MockTurnOffDigitalLightHandler: public TurnOffSwitchableHandler<MockDigitalLightHw> {

public:

    MockTurnOffDigitalLightHandler(std::list<MockDigitalLightHw*> components)
        : TurnOffSwitchableHandler<MockDigitalLightHw>("turnOff", components) {

    };

};

#endif //BRITTANY_MOCK_TURN_OFF_DIGITAL_LIGHT_HANDLER_INTERFACE_H
