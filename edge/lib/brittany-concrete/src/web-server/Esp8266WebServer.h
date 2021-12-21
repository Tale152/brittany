#ifndef BRITTANY_ESP8266_WEB_SERVER_H
#define BRITTANY_ESP8266_WEB_SERVER_H

#include "web-server/WebServer.h"
#include "edge/Edge.h"
#include "ESP8266WebServer.h"
#include "HttpStatusCodes_C++.h"
#include "json_util.h"

/**
 * @brief ESP8266WebServer implementation of web server.
 * 
 */
class Esp8266WebServer : public WebServer{

public:

    /**
     * @brief Construct a new Esp8266Web Server object. Attach all the Edge handlers, the
     *        not found handler and the TD handler.
     * 
     * @param e edge reference used by super constructor.
     * @param port the port of the web server.
     */
    Esp8266WebServer(Edge* e, int port = DEFAULT_WEB_SERVER_PORT): WebServer(e, port), _server{port} {
        Serial.println("Available Server path:");
        _server.onNotFound([&] () {
            _server.send(
                HttpStatus::NotFound,
                "text/plain",
                "URI not found: " + _server.uri()
            );
        });

        Serial.println("/");
        _server.on("/", [&] () {
            _server.send(
                HttpStatus::OK,
                "application/json",
                stringify(edge() -> thingDescriptor()).c_str()
            );
        });

        for(std::string p : edge() -> availablePaths()) {
            Serial.println(p.c_str());
            _server.on(p.c_str(), [&, p] () {
                Json::Value args;
                for(int i = 0; i < _server.args(); i++) {    
                    args[_server.argName(i).c_str()] = _server.arg(i).c_str();
                }
                OperationHandlerResult result = edge() -> execute(p, args);
                _server.send(
                    result.code(),
                    "application/json",
                    stringify(result.content()).c_str()
                );
            });
        }
    } 

    void begin() {
        _server.begin();
    }

    /**
     * @brief Used to handle the client requests in the super loop.
     */
    void handleClient() {
        _server.handleClient();
    }

private:

    ESP8266WebServer _server;

};

#endif //BRITTANY_ESP8266_WEB_SERVER_H