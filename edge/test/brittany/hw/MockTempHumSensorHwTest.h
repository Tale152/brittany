#include <unity.h>
#include <optional>
#include "hw/MockTempHumSensorHw.h"

#define MOCK_TEMP_HUM_SENSOR_NAME "temp-hum"
#define MOCK_TEMP_HUM_SENSOR_PIN 0
#define MOCK_TEMP_HUM_SENSOR_CELSIUS 12.5
#define MOCK_TEMP_HUM_SENSOR_HUMIDITY 50

MockTempHumSensorHw tempHum = 
    MockTempHumSensorHw(
        MOCK_TEMP_HUM_SENSOR_NAME,
        MOCK_TEMP_HUM_SENSOR_PIN,
        MOCK_TEMP_HUM_SENSOR_CELSIUS,
        MOCK_TEMP_HUM_SENSOR_HUMIDITY
    );

MockTempHumSensorHw brokenTempHum = 
    MockTempHumSensorHw(
        MOCK_TEMP_HUM_SENSOR_NAME,
        MOCK_TEMP_HUM_SENSOR_PIN,
        std::nullopt,
        std::nullopt
    );


void test_mock_celsius() {
    TEST_ASSERT_EQUAL_FLOAT(
        MOCK_TEMP_HUM_SENSOR_CELSIUS,
        tempHum.temperatureCelsius().value()
    );
    TEST_ASSERT_FALSE(brokenTempHum.temperatureCelsius().has_value());
}

void test_mock_fahrenheit() {
    TEST_ASSERT_EQUAL_FLOAT(
        MOCK_TEMP_HUM_SENSOR_CELSIUS * 1.8 + 32,
        tempHum.temperatureFahrenheit().value()
    );
    TEST_ASSERT_FALSE(brokenTempHum.temperatureFahrenheit().has_value());
}

void test_mock_kelvin() {
    TEST_ASSERT_EQUAL_FLOAT(
        MOCK_TEMP_HUM_SENSOR_CELSIUS + 273.15,
        tempHum.temperatureKelvin().value()
    );
    TEST_ASSERT_FALSE(brokenTempHum.temperatureKelvin().has_value());
}

void test_mock_humidity() {
    TEST_ASSERT_EQUAL_FLOAT(
        MOCK_TEMP_HUM_SENSOR_HUMIDITY,
        tempHum.humidity().value()
    );
    TEST_ASSERT_FALSE(brokenTempHum.humidity().has_value());
}

void test_MockTempHumSensorHwTest() {
    RUN_TEST(test_mock_celsius);
    RUN_TEST(test_mock_fahrenheit);
    RUN_TEST(test_mock_kelvin);
    RUN_TEST(test_mock_humidity);
}
