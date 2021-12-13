#ifndef BRITTANY_MOCK_DIGITAL_LIGHT_HW_TEST_H
#define BRITTANY_MOCK_DIGITAL_LIGHT_HW_TEST_H

#include <unity.h>
#include "digital-light/mock/MockDigitalLightHw.h"

#define DIGITAL_LIGHT_ID "light"
#define DIGITAL_LIGHT_PIN 10

MockDigitalLightHw mockDigitalLight = MockDigitalLightHw(DIGITAL_LIGHT_ID, DIGITAL_LIGHT_PIN);

void test_get_mock_digital_light_id() {
    TEST_ASSERT_EQUAL_STRING(mockDigitalLight.id().c_str(), DIGITAL_LIGHT_ID);
}

void test_get_mock_digital_light_pin() {
    TEST_ASSERT_EQUAL(mockDigitalLight.pin(), DIGITAL_LIGHT_PIN);
}

void test_mock_digital_light_is_on() {
    TEST_ASSERT_TRUE(mockDigitalLight.isOn());
}

void test_mock_digital_light_is_off() {
    TEST_ASSERT_FALSE(mockDigitalLight.isOn());
}

void test_mock_digital_light_on_operation() {
    mockDigitalLight.on();
    test_mock_digital_light_is_on();
}

void test_mock_digital_light_off_operation() {
    mockDigitalLight.off();
    test_mock_digital_light_is_off();
}

void test_MockDigitalLightHw() {
    RUN_TEST(test_get_mock_digital_light_id);
    RUN_TEST(test_get_mock_digital_light_pin);
    RUN_TEST(test_mock_digital_light_is_off); // test that light is initally off.
    RUN_TEST(test_mock_digital_light_on_operation);
    RUN_TEST(test_mock_digital_light_off_operation);
}

#endif //BRITTANY_MOCK_DIGITAL_LIGHT_HW_TEST_H