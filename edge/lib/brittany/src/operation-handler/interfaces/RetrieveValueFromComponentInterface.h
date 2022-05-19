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

#ifndef RETRIEVE_VALUE_FROM_COMPONENT_INTERFACE_H
#define RETRIEVE_VALUE_FROM_COMPONENT_INTERFACE_H

#include <string>
#include <list>
#include "operation-handler/interfaces/ValueReturnedAfterActionHandlerInterface.h"

template <class C, class T>

class RetrieveValueFromComponentInterface : public ValueReturnedAfterActionHandlerInterface<T> {

public:

    /**
     * @brief Construct a new Retrieve Value From Component Interface object.
     * 
     * @param name the name of the operation handler.
     * @param operationType the operation type.
     * @param returnedType the returned type.
     * @param components the list of components.
     */
    RetrieveValueFromComponentInterface(
        std::string name,
        OperationType operationType,
        Type returnedType,
        std::list<C*> components
    )
    : ValueReturnedAfterActionHandlerInterface<T> (
        name,
        operationType,
        returnedType
    ) {
        _components = components;
    };

    /**
     * @brief Construct a new Retrieve Value From Component Interface object.
     *        Simplified Constructor that set the handler to a property and return a number.
     * 
     * @param name the name of the operation handler.
     * @param components the list of components.
     */
    RetrieveValueFromComponentInterface(
        std::string name,
        std::list<C*> components
    )
    : ValueReturnedAfterActionHandlerInterface<T> (
        name,
        OperationType::PROPERTY,
        Type::NUMBER
    ) {
        _components = components;
    };

private:

    std::optional<T> retrieveValue(Json::Value args) {
        std::optional<C*> oc = find_by_id(_components, args["id"].asCString());
        if(oc.has_value()) {
            std::optional<T> opt_value = sub_operation(oc.value(), args);
            if(opt_value.has_value()) {
                return opt_value.value();
            }
        }
        return std::nullopt;
    }

    virtual std::optional<T> sub_operation(C* hw, Json::Value args) = 0;

    std::list<C*> _components;
};

#endif //RETRIEVE_VALUE_FROM_COMPONENT_INTERFACE_H
