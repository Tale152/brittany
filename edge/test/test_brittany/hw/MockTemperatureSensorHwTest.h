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
#include "mock-temperature-sensor/hw/MockTemperatureSensorHw.h"

#define MOCK_TEMPERATURE_TEST_ATTEMPT 100
#define MOCK_TEMPERATURE_SENSOR_NAME "jotaro"

MockTemperatureSensorHw mockTemperatureSensor =
    MockTemperatureSensorHw(MOCK_TEMPERATURE_SENSOR_NAME);


void mock_temperature_value_is_valid(int value, int min, int max) {
    TEST_ASSERT_TRUE(value <= max && value >= min);
}

void test_mock_temperature_celsius() {
    std::optional<float> tempC = mockTemperatureSensor.temperatureCelsius();
    TEST_ASSERT_TRUE(tempC.has_value());
    mock_temperature_value_is_valid(tempC.value(), 0, MOCK_MAX_TEMPERATURE_CELSIUS); 
}

void test_mock_temperature_fahrenheit() {
    std::optional<float> tempF = mockTemperatureSensor.temperatureFahrenheit();
    TEST_ASSERT_TRUE(tempF.has_value());
    mock_temperature_value_is_valid(
        tempF.value(),
        Temperature::fromCToF(0),
        Temperature::fromCToF(MOCK_MAX_TEMPERATURE_CELSIUS)
    ); 
}

void test_mock_temperature_kelvin() {
    std::optional<float> tempK = mockTemperatureSensor.temperatureKelvin();
    TEST_ASSERT_TRUE(tempK.has_value());
    mock_temperature_value_is_valid(
        tempK.value(),
        Temperature::fromCToK(0),
        Temperature::fromCToK(MOCK_MAX_TEMPERATURE_CELSIUS)
    ); 
}

void test_mock_temperature() {
    for(int i = 0; i < MOCK_TEMPERATURE_TEST_ATTEMPT; i++) {
        test_mock_temperature_celsius();
        test_mock_temperature_fahrenheit();
        test_mock_temperature_kelvin();
    }
}

void test_MockTemperatureSensorHwTest() {
    RUN_TEST(test_mock_temperature);
}
