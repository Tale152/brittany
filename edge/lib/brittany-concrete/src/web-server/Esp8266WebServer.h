#ifndef BRITTANY_ESP8266_WEB_SERVER_H
#define BRITTANY_ESP8266_WEB_SERVER_H

#include "web-server/WebServer.h"
#include "edge/Edge.h"
#include "ESP8266WebServer.h"

class Esp8266WebServer : public WebServer{

public:

    Esp8266WebServer(Edge edge, int port = DEFAULT_WEB_SERVER_PORT): WebServer(edge, port), _server{port} {
        for(std::string p : edge.availablePaths()) {
            _server.on(p.c_str(), [&] () {
                Json::Value args;
                for(int i = 0; i < _server.args(); i++) {    
                    args[_server.argName(i).c_str()] = _server.arg(i).c_str();
                }
                OperationHandlerResult result = edge.execute(p, args);
                _server.send(result.code(), "application/json", result.content().asString().c_str());
            });
        }
    }  

    void begin() {
        _server.begin();
    }

private:

    ESP8266WebServer _server;

};

#endif //BRITTANY_ESP8266_WEB_SERVER_H