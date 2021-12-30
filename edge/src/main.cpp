#include <Arduino.h>
#include "web-server/Esp8266WebServer.h"
#include "hw/MockDigitalLightHw.h"
#include "modules/MockDigitalLightModule.h"
#include <json_util.h>
#include "wifi_secret.h"
#include <list>
#include "temp-hum-sensor/hw/DHT22SensorHw.h"
#include "modules/DHT22Module.h"
#include "modules/Module.h"


std::list<Module*> modules;
Esp8266WebServer* server;


#ifdef BRITTANY_MAIN_MOCK_DIGITAL_LIGHT

void setup_variables() {
    MockDigitalLightHw* light0 = new MockDigitalLightHw("0", 0);
    MockDigitalLightHw* light1 = new MockDigitalLightHw("1", 1);
    std::list<MockDigitalLightHw*> lights = std::list<MockDigitalLightHw*>({light0, light1});
    modules.push_back(new MockDigitalLightModule("light", lights));
    Edge* edge = new Edge(modules);
    server = new Esp8266WebServer(edge);
}

#endif


#ifdef BRITTANY_MAIN_DHT22

void setup_variables() {
    DHT22SensorHw* dht22 = new DHT22SensorHw("dht22", D5);
    std::list<DHT22SensorHw*> sensors = std::list<DHT22SensorHw*>({dht22});
    modules.push_back(new DHT22Module("temp-hum", sensors));
    Edge* edge = new Edge(modules);
    server = new Esp8266WebServer(edge);
}

#endif

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

void setup() {
    Serial.begin(115200);
    connect_to_wifi();
    setup_variables();
    server -> begin();
}

void loop() {
    server -> handleClient();
}
