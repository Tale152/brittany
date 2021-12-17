#include <unity.h>
#include "web-server/Esp8266WebServer.h"
#include "edge/Edge.h"
#include "MockSerialArgsOperationHandler.h"
#include <ESP8266HTTPClient.h>

#define ESP_8266_OPERATION_HANDLER_PATH "/example"

MockSerialArgsOperationHandler* esp8266Handler = new MockSerialArgsOperationHandler(ESP_8266_OPERATION_HANDLER_PATH);
Edge esp8266ServerEdge = Edge(std::list<OperationHandler*> {esp8266Handler});
Esp8266WebServer esp8266Server = Esp8266WebServer(esp8266ServerEdge);

void test_esp8266_web_server_begin() {
    esp8266Server.begin();
    //TODO...
}

void test_Esp8266WebWerver() {
    RUN_TEST(test_esp8266_web_server_begin);
}

