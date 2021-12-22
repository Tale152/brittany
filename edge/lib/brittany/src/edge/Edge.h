#ifndef BRITTANY_EDGE_H
#define BRITTANY_EDGE_H

#include <string>
#include <list>
#include <json/json.h>
#include "operation-handler/OperationHandler.h"
#include "operation-handler/OperationHandlerResult.h"
#include "thing-descriptor/ThingDescriptor.h"
#include "modules/Module.h"

/**
 * @brief Class that acts as a container of the Edge OperationHandlers.
 */
class Edge {

public:

    /**
     * @brief Construct a new Edge object.
     * 
     * @param modules The modules that the edge contains.
     */
    Edge(std::list<Module*> modules);
    
    /**
     * @brief Execute the handler whit the specified name and args.
     * 
     * @param route the path of the handler to execute.
     * @param args the arguments to pass to the handler.
     * @return OperationHandlerResult the result of the handler execution.
     */
    OperationHandlerResult execute(std::string route, Json::Value args);

    /**
     * @brief Get all the available path list.
     * 
     * @return std::list<std::string> 
     */
    std::list<std::string> availablePaths();

    /**
     * @brief Return the Edge Thing Descriptor.
     * 
     * @return Json::Value the Edge Thing Descriptor
     */
    Json::Value thingDescriptor();

private:

    std::list<Module*> _modules;
    
};

#endif //BRITTANY_EDGE_H