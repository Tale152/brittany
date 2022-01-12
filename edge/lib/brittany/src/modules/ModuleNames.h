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
            return "humidity";
        case ModuleNames::Light:
            return "light";
        default:
            return "";
    }
}

#endif // MODULE_NAMES_H