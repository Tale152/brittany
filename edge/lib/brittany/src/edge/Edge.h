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

#ifndef BRITTANY_EDGE_H
#define BRITTANY_EDGE_H

#include <string>
#include <list>
#include <json/json.h>
#include "operation-handler/OperationHandler.h"
#include "operation-handler/OperationHandlerResult.h"
#include "modules/Module.h"

/**
 * @brief Class that acts as a container of the Edge OperationHandlers.
 */
class Edge {

public:

    /**
     * @brief Construct a new Edge object.
     * 
     * @param title The title of the Edge.
     * @param modules The modules that the edge contains.
     */
    Edge(std::string title, std::list<Module*> modules);
    

    /**
     * @brief get the Edge title.
     * 
     * @return std::string Return the Edge title.
     */
    std::string title();

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
     * @param ip The ip to insert in the TD.
     * @param port The port to insert in the TD.
     * @return Json::Value the Edge Thing Descriptor
     */
    Json::Value thingDescriptor(std::string ip, int port);

private:

    std::string _title;
    std::list<Module*> _modules;
    
};

#endif //BRITTANY_EDGE_H