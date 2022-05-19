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
#include "temp-hum-sensor/dht22/hw/DHT22SensorHw.h"

#define DHT22_SENSOR_NAME "dht22"
#define DHT22_SENSOR_PIN D1
#define DELTA_VALUE 1

DHT22SensorHw dht22 = DHT22SensorHw(DHT22_SENSOR_NAME, DHT22_SENSOR_PIN);

std::optional<float> c;

bool is_around_this_value(float expected, float value) {
    return (expected + DELTA_VALUE > value && expected - DELTA_VALUE < value);
}

void is_value_present(std::optional<float> value) {
    TEST_ASSERT_TRUE(value.has_value());
}

void test_dht22_celsius() {
    c = dht22.temperatureCelsius();
    is_value_present(c);
    TEST_ASSERT_TRUE(c.value() >= -273.15);
}

void test_dht22_fahrenheit() {
    std::optional<float> f = dht22.temperatureFahrenheit();
    is_value_present(f);
    TEST_ASSERT_TRUE(is_around_this_value(Temperature::fromCToF(c.value()), f.value()));
    TEST_ASSERT_TRUE(c.value() >= -459.67);
}

void test_dht22_kelvin() {
    std::optional<float> k = dht22.temperatureKelvin();
    is_value_present(k);
    TEST_ASSERT_TRUE(is_around_this_value(Temperature::fromCToK(c.value()), k.value())); 
    TEST_ASSERT_TRUE(k.value() > 0);
}

void test_dht22_humidity() {
    std::optional<float> h = dht22.humidity();
    is_value_present(h);
    TEST_ASSERT_TRUE(h.value() >= 0);
    TEST_ASSERT_TRUE(h.value() <= 100);
}

void test_DHT22SensorHW() {
    RUN_TEST(test_dht22_celsius);
    RUN_TEST(test_dht22_fahrenheit);
    RUN_TEST(test_dht22_kelvin);
    RUN_TEST(test_dht22_humidity);
}
