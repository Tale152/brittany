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
#include "mock-digital-light/hw/MockDigitalLightHw.h"

#define DIGITAL_LIGHT_ID "light"

MockDigitalLightHw mockDigitalLight = MockDigitalLightHw(DIGITAL_LIGHT_ID);

void test_get_mock_digital_light_id() {
    TEST_ASSERT_EQUAL_STRING(mockDigitalLight.id().c_str(), DIGITAL_LIGHT_ID);
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
    RUN_TEST(test_mock_digital_light_is_off); // test that light is initally off.
    RUN_TEST(test_mock_digital_light_on_operation);
    RUN_TEST(test_mock_digital_light_off_operation);
}
