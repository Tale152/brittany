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

#ifndef BRITTANY_IS_ON_SWITCHABLE_HANDLER_H
#define BRITTANY_IS_ON_SWITCHABLE_HANDLER_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/RetrieveValueFromComponentInterface.h"
#include "util.h"

template <class C>

class IsOnSwitchableHandler: public RetrieveValueFromComponentInterface<C, bool> {

public:

    IsOnSwitchableHandler(
        std::string name,
        std::list<C*> components
    ): RetrieveValueFromComponentInterface<C, bool>(
        name,
        OperationType::PROPERTY,
        Type::BOOLEAN,
        components
    ) {

    }

private:

    std::optional<bool> sub_operation(C* hw, Json::Value args) {
        return std::optional(hw -> isOn());
    }

};

#endif //BRITTANY_IS_ON_SWITCHABLE_HANDLER_H
