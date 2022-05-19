/* * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <unity.h>
#include <Arduino.h>
#include "digital-light/hw/DigitalLightHw.h"

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
