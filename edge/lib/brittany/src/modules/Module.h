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