#include <unity.h>
#include <Arduino.h>
#include "hw/DigitalLightHwTest.h"
#include "web-server/Esp8266WebServerTest.h"

void setup() {
    UNITY_BEGIN();
    test_DigitalLightHw(); //DigitalLightHwTest
    test_Esp8266WebWerver(); //Esp8266WebServerTest
    UNITY_END();
}

void loop() {

}
