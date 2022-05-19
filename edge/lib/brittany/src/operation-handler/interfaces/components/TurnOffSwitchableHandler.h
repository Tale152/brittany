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

#ifndef BRITTANY_TURN_OFF_SWITCHABLE_HANDLER_H
#define BRITTANY_TURN_OFF_SWITCHABLE_HANDLER_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/RetrieveValueFromComponentInterface.h"
#include "util.h"

template <class C>

class TurnOffSwitchableHandler
: public RetrieveValueFromComponentInterface<C, std::string> {

public:

    TurnOffSwitchableHandler(
        std::string name,
        std::list<C*> components
    ): RetrieveValueFromComponentInterface<C, std::string>(
        name,
        OperationType::ACTION,
        Type::STRING,
        components
    ) {

    }

private:

    std::optional<std::string> sub_operation(C* hw, Json::Value args) {
        hw -> off();
        return std::optional(phrase(ContentResult::Ok));
    };

};

#endif //BRITTANY_TURN_OFF_SWITCHABLE_HANDLER_H
