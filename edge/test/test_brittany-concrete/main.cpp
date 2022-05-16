#include <unity.h>
#include <Arduino.h>
#include "hw/DigitalLightHwTest.h"
#include "hw/DHT22HwSensorTest.h"

void setup() {
    delay(7000);
    UNITY_BEGIN();
    Serial.begin(115200);
    test_DigitalLightHw(); //DigitalLightHwTest
    test_DHT22SensorHW(); //DHT22HwSensorTest
    UNITY_END();
}

void loop() {

}
