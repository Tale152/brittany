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
#include "modules/dht22.h"
#include "modules/mock-digital-light.h"

Esp8266WebServer* server;

void setup_variables() {
    server = new Esp8266WebServer(edge());
}

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
