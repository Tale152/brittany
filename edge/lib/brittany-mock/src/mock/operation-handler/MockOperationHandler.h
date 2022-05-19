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

#ifndef BRITTANY_MOCK_OPERATION_HANDLER_H
#define BRITTANY_MOCK_OPERATION_HANDLER_H

#include <string>
#include <json/json.h>
#include "operation-handler/OperationHandlerResult.h"
#include "operation-handler/OperationHandler.h"
#include "HttpStatusCodes_C++.h"

/**
 * @brief Class that represents a mock OperationHandler used only for testing purposes.
 */
class MockOperationHandler: public OperationHandler {

public:

    MockOperationHandler() :
        OperationHandler("value", OperationType::PROPERTY, Type::INTEGER) {
        _value = 0;
    };

    virtual OperationHandlerResult handle(Json::Value args) {
        _value = _value + args.asInt();
        return OperationHandlerResult(HttpStatus::OK, Json::Value(_value));
    };

private:

    int _value;

};

#endif //BRITTANY_OPERATION_HANDLER_H