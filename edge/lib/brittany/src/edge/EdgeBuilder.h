#ifndef BRITTANY_EDGE_BUILDER_H
#define BRITTANY_EDGE_BUILDER_H

#include "modules/Module.h"
#include "edge/Edge.h"
#include "operation-handler/OperationHandler.h"
#include <list>

/**
 * @brief Builder that creates an Edge object from some Modules.
 * 
 */
class EdgeBuilder {

public:

    /**
     * @brief Construct a new Edge Builder object.
     * 
     */
    EdgeBuilder();

    /**
     * @brief add a module to the builder.
     * 
     * @param module the module to add.
     */
    void addModule(Module module);

    /**
     * @brief add all the modules in the list to the builder.
     * 
     * @param modules the modules to add.
     */
    void addAllModules(std::list<Module> modules);

    /**
     * @brief Create an Edge object from the modules.
     * 
     * @return Edge An Edge Object that contains all the handlers contained in the modules added previously.
     */
    Edge* build();

private:

    std::list<Module> _modules;
    
};

#endif //BRITTANY_EDGE_BUILDER_H