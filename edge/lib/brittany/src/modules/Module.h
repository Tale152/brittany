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
    Module();

    /**
     * @brief Return the list of OperationHandler in this Module.
     * 
     * @return std::list<OperationHandler*> the handlers list.
     */
    std::list<OperationHandler*> handlers();

protected:

    std::list<OperationHandler*> _handlers;
};

#endif //BRITTANY_MODULE_H