#include <unity.h>
#include <Arduino.h>
#include "hw/DigitalLightHwTest.h"
#include "util/Esp8266HttpRequestorTest.h"
#include "wifi_secret.h"

void connectToWifi(){
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

bool webServerTestIsDone = false;

void setup() {
    delay(7000);
    UNITY_BEGIN();
    Serial.begin(115200);
    connectToWifi();
    test_DigitalLightHw(); //DigitalLightHwTest
    test_Esp8266HttpRequestor(); //Esp8266HttpRequestorTest
    UNITY_END();
}

void loop() {

}
