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