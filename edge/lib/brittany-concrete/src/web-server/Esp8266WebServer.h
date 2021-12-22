#ifndef BRITTANY_ESP8266_WEB_SERVER_H
#define BRITTANY_ESP8266_WEB_SERVER_H

#include "web-server/WebServer.h"
#include "edge/Edge.h"
#include "ESP8266WebServer.h"
#include "HttpStatusCodes_C++.h"
#include "json_util.h"
#include "util/DebugPrint.h"

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
    Esp8266WebServer(Edge* e, int port = DEFAULT_WEB_SERVER_PORT):
        WebServer(e, port),
        _server{port},
        _debug(true) {
        _debug.println("Available Server path:");
        _server.onNotFound([&] () {
            _server.send(
                HttpStatus::NotFound,
                "text/plain",
                "URI not found: " + _server.uri()
            );
        });

        _debug.println("/");
        _server.on("/", [&, port] () {
            _server.send(
                HttpStatus::OK,
                "application/json",
                stringify(edge() -> thingDescriptor(WiFi.localIP().toString().c_str(), port)).c_str()
            );
        });

        for(std::string p : edge() -> availablePaths()) {
            _debug.println(p);
            _server.on(p.c_str(), [&, p] () {
                Json::Value args;
                for(int i = 0; i < _server.args(); i++) {
                    args[_server.argName(i).c_str()] = _server.arg(i).c_str();
                    _debug.println(_server.arg(i).c_str());
                }
                _debug.println("Request received, forwarded to:");
                _debug.println(_server.uri().c_str());
                _debug.println("Arguments:");
                _debug.println(stringify(args));
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
    DebugPrint _debug;

};

#endif //BRITTANY_ESP8266_WEB_SERVER_H