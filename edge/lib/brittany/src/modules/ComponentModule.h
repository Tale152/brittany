#ifndef BRITTANY_COMPONENT_MODULE_H
#define BRITTANY_COMPONENT_MODULE_H

#include "Module.h"
#include <list>

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
    ComponentModule(std::string name, std::list<T*> components);

    /**
     * @brief Get the components used by the modules
     * 
     * @return std::list<T*> A list containing all the components in the module. 
     */
    std::list<T*> components();

private:

    std::list<T*> _components;
};

#endif //BRITTANY_COMPONENT_MODULE_H