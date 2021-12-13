#include BRITTANY_DIGITAL_LIGHT_HW_TEST
#define BRITTANY_DIGITAL_LIGHT_HW_TEST

#include <unity.h>
#include <Arduino.h>
#include "digital-light/DigitalLightHw.h"

#define DIGITAL_LIGHT_ID "digital-light"
#define DIGITAL_LIGHT_PIN LED_BUILTIN
#define ON_OFF_TEST_ATTEMPT 10

DigitalLightHw digitalLightHw = DigitalLightHw(DIGITAL_LIGHT_ID, DIGITAL_LIGHT_PIN);

void test_digital_light_id() {
    TEST_ASSERT_EQUAL_STRING(DIGITAL_LIGHT_ID, digitalLightHw.id().c_str());
}

void test_digital_light_pin() {
    TEST_ASSERT_EQUAL(DIGITAL_LIGHT_PIN, digitalLightHw.pin());
}

void test_digital_light_is_on() {
    TEST_ASSERT_TRUE(digitalLightHw.isOn());
}

void test_digital_light_is_off() {
    TEST_ASSERT_FALSE(digitalLightHw.isOn());
}

void test_digital_light_on_operation() {
    digitalLightHw.on();
    test_digital_light_is_on();
}

void test_digital_light_off_operation() {
    digitalLightHw.off();
    test_digital_light_is_off();
}

void test_DigitalLightHw() {
    RUN_TEST(test_digital_light_id);
    RUN_TEST(test_digital_light_pin);
    RUN_TEST(test_digital_light_is_off);
    for(int i = 0; i < ON_OFF_TEST_ATTEMPT; i++){
        RUN_TEST(test_digital_light_on_operation);
        RUN_TEST(test_digital_light_off_operation);
        delay(100);
    }
}

#endif