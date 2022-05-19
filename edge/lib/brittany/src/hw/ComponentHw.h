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

#ifndef BRITTANY_COMPONENTHW_H
#define BRITTANY_COMPONENTHW_H

#include <string>

/**
 * @brief Class representing a hardware component.
 * 
 */
class ComponentHw {

public:

    /**
     * @brief Construct a new Component Hw object.
     * 
     * @param id the unique id of the component.
     */
    ComponentHw(std::string id);

    /**
     * @brief get the id of the component.
     * 
     * @return std::string the component id.
     */
    std::string id();

private:

    std::string _id;

};


#endif //BRITTANY_COMPONENTHW_H
