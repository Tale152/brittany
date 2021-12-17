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
     * @param edge The edge object used to create the WebServer.
     * @param port The port of the Web Server, default is 80.
     */
    WebServer(Edge edge, int port = DEFAULT_WEB_SERVER_PORT) {
        //does nothing
    };

    /**
     * @brief Start the WebServer.
     */
    virtual void begin() = 0;

};

#endif //BRITTANY_WEB_SERVER_BUILDER_H