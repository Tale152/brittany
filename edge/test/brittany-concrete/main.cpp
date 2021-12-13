#include <Arduino.h>
#include <unity.h>
#include "hw/DigitalLightHwTest.h"

void setup() {
    UNITY_BEGIN();
    test_DigitalLightHw(); //DigitalLightHwTest
    UNITY_END();
}

void loop() {

}