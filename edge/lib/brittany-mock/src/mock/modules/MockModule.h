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

#ifndef BRITTANY_MOCK_MODULE_H
#define BRITTANY_MOCK_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"
#include "../operation-handler/MockOperationHandler.h"
#include "modules/Module.h"
#include "util.h"
#include "operation-handler/types/OperationType.h"

#define OPERATION_HANDLER_IN_MOCK_MODULE_NAME "value"

/**
 * @brief Mock Module that contains only a MockOperationHandler.
 */
class MockModule : public Module {

public:

    MockModule(std::string name): Module(name) {
        _handlers.push_back(new MockOperationHandler());
    };

};

#endif //BRITTANY_MOCK_COMPONENT_MODULE_H