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
#include <optional>
#include "mock-humidity-sensor/hw/MockHumiditySensorHw.h"

#define MOCK_HUMIDITY_TEST_ATTEMPT 100
#define MOCK_HUMIDITY_SENSOR_NAME "jotaro"

MockHumiditySensorHw mockHumiditySensor =
    MockHumiditySensorHw(MOCK_HUMIDITY_SENSOR_NAME);

void mock_humidity_value_is_valid(int value, int min, int max) {
    TEST_ASSERT_TRUE(value <= max && value >= min);
}

void test_mock_humidity_value() {
    std::optional<float> hum = mockHumiditySensor.humidity();
    TEST_ASSERT_TRUE(hum.has_value());
    mock_temperature_value_is_valid(hum.value(), 0, MOCK_MAX_HUMIDITY); 
}

void test_mock_humidity_sensor() {
    for(int i = 0; i < MOCK_TEMPERATURE_TEST_ATTEMPT; i++) {
        test_mock_humidity_value();
    }
}

void test_MockHumiditySensorHwTest() {
    RUN_TEST(test_mock_humidity_sensor);
}
