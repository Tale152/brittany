#ifndef BRITTANY_MODULE_H
#define BRITTANY_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"

/**
 * @tparam T The generic type of the components in the module.
 */
template<class T>

/**
 * @brief A class that wrap some components and some OperationHandler that maniupulate them.
 */
class Module {

public:

    /**
     * @brief Construct a new Module object. Handlers are created here in subclasses.
     * 
     * @param components 
     */
    Module(std::list<T*> components);

    /**
     * @brief Return the list of OperationHandler in this Module.
     * 
     * @return std::list<OperationHandler*> 
     */
    std::list<OperationHandler*> handlers();

protected:

    std::list<OperationHandler*> _handlers;
};

#endif //BRITTANY_MODULE_H