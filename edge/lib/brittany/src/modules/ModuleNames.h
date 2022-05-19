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

#ifndef MODULE_NAMES_H
#define MODULE_NAMES_H

#include "hw/ComponentHw.h"
#include <list>
#include <string>
#include <optional>

/**
 * @brief Enum to define the module names used by the system.
 */
enum class ModuleNames {
    Temperature,
    Humidity,
    Light
};

/**
 * @brief Return the Module name as a string.
 * 
 * @param moduleName the ModuleNames value.
 * @return std::string A string that represent the passed value.
 */
inline std::string module_as_string(ModuleNames moduleName) {
    switch (moduleName) {
        case ModuleNames::Temperature:
            return "temperature";
        case ModuleNames::Humidity:
            return "airHumidity";
        case ModuleNames::Light:
            return "light";
        default:
            return "";
    }
}

#endif // MODULE_NAMES_H