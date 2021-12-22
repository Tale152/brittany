#include <Arduino.h>
#include "web-server/Esp8266WebServer.h"
#include "hw/MockDigitalLightHw.h"
#include "modules/MockDigitalLightModule.h"
#include <json_util.h>
#include "wifi_secret.h"
#include <list>

Esp8266WebServer* server;

void connect_to_wifi() {
    WiFi.begin(WIFI_SSID, WIFI_PSWD);
    Serial.print("Connecting to ");
    Serial.print(WIFI_SSID);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print('.');
    }
    Serial.println('\n');
    Serial.println("Connection established!");  
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());  
}

void setup_variables() {
    MockDigitalLightHw* light0 = new MockDigitalLightHw("0", 0);
    MockDigitalLightHw* light1 = new MockDigitalLightHw("1", 1);
    std::list<MockDigitalLightHw*> lights = std::list<MockDigitalLightHw*>({light0, light1});
    std::list<Module*> modules = std::list<Module*>({new MockDigitalLightModule("light", lights)});
    Edge* edge = new Edge(modules);
    server = new Esp8266WebServer(edge);
}

void setup() {
    Serial.begin(115200);
    connect_to_wifi();
    setup_variables();
    server -> begin();
}

void loop() {
    server -> handleClient();
}