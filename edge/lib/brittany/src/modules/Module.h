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

#ifndef BRITTANY_MODULE_H
#define BRITTANY_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"

/**
 * @brief Class that wraps a collection of handlers.
 * 
 */
class Module {

public:

    /**
     * @brief Construct a new Module object.
     */
    Module(std::string name);

    /**
     * @brief Return the list of OperationHandler in this Module.
     * 
     * @return std::list<OperationHandler*> the handlers list.
     */
    std::list<OperationHandler*> handlers();

    /**
     * @brief Get the Module name.
     * 
     * @return std::string return the module name as string.
     */
    std::string name();

protected:

    std::list<OperationHandler*> _handlers;
    std::string _name;
};

#endif //BRITTANY_MODULE_H