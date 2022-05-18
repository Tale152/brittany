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
