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

#ifndef BRITTANY_WEB_SERVER_H
#define BRITTANY_WEB_SERVER_H

#include "edge/Edge.h"

#define DEFAULT_WEB_SERVER_PORT 80

/**
 * @brief Class that represent a WebServer. An Edge object is required to create one.
 * 
 */
class WebServer {

public:

    /**
     * @brief Construct a new Web Server object.
     * 
     * @param edge The edge object ref used to create the WebServer.
     * @param port The port of the Web Server, default is 80.
     */
    WebServer(Edge* edge, int port = DEFAULT_WEB_SERVER_PORT) {
        _edge = edge;
    };

    /**
     * @brief Start the WebServer.
     */
    virtual void begin() = 0;

protected:

    /**
     * @brief Return the Edge reference.
     * 
     * @return Edge* the Edge Reference
     */
    Edge* edge(){
        return _edge;
    }

private:

    Edge* _edge;
};

#endif //BRITTANY_WEB_SERVER_BUILDER_H