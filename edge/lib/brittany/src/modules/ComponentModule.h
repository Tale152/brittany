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
     * @param components 
     */
    ComponentModule(std::list<T*> components);

};

#endif //BRITTANY_COMPONENT_MODULE_H