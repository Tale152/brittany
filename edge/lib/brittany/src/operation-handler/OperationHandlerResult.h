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

#ifndef BRITTANY_OPERATION_HANDLER_RESULT_H
#define BRITTANY_OPERATION_HANDLER_RESULT_H

#include "json/json.h"
#include "operation-handler/types/Type.h"

/**
 * @brief A class that wraps the results information of an OperationHandler.
 */
class OperationHandlerResult {

public:

    /**
     * @brief Construct a new Operation Handler Result object.
     * 
     * @param code the code of the result.
     * @param content a json value containing information about the result.
     */
    OperationHandlerResult(int code, Json::Value content);

    /**
     * @brief Return the result code.
     * 
     * @return int a code that identify what occurence happened executing the OperationHandler.
     */
    int code();

    /**
     * @brief Return the Json value.
     * 
     * @return Json::Value a json value that contains information of what happened when executing the OperationHandler.
     */
    Json::Value content();

private:

    int _code;
    Json::Value _content;

};

#endif //BRITTANY_OPERATION_HANDLER_RESULT_H