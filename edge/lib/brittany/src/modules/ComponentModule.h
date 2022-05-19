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

#ifndef BRITTANY_COMPONENT_MODULE_H
#define BRITTANY_COMPONENT_MODULE_H

#include "Module.h"
#include <list>
#include "hw/ComponentHw.h"

/**
 * @tparam T Template used to pass any component type to ComponentModule.
 */
template<class T>

/**
 * @brief A Module that uses a list of the generic type T to create handlers.
 * 
 */
class ComponentModule : public Module {

public:

    /**
     * @brief Construct a new Module object. Handlers are created here in subclasses.
     * 
     * @param name the name of the module.
     * @param components the components list.
     */
    ComponentModule(std::string name, std::list<T*> components) : Module(name) {
        for(T* t : components) {
            _components.push_back(ComponentHw(t -> id()));
        }
    }

    /**
     * @brief Return the list of ComponentHw in this module.
     * 
     * @return std::list<ComponentHw> A list of ComponentHw.
     */
    std::list<ComponentHw> components() {
        return _components;
    }

private:

    std::list<ComponentHw> _components;
};

#endif //BRITTANY_COMPONENT_MODULE_H