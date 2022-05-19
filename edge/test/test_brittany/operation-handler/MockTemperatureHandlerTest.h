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

#ifndef MOCK_TEMPERATURE_HANDLER_TEST_H
#define MOCK_TEMPERATURE_HANDLER_TEST_H

#include <list>
#include <unity.h>
#include "mock-temperature-sensor/operation-handler/MockTemperatureHandler.h"
#include "mock-temperature-sensor/hw/MockTemperatureSensorHw.h"

#define MOCK_TEMPERATURE_SENSOR_NAME_IN_HANDLER "sensor"

MockTemperatureHandler* mockTemperatureHandler;
MockTemperatureSensorHw* mockTempSensor;

Json::Value argsMockTempSensor;
Json::Value argsMockTempSensorBadReq;
Json::Value argsMockTempSensorNotFound;

void setup_mock_temperature_handler() {
    mockTempSensor = new MockTemperatureSensorHw(MOCK_TEMPERATURE_SENSOR_NAME_IN_HANDLER);
    argsMockTempSensor["id"] = MOCK_TEMPERATURE_SENSOR_NAME_IN_HANDLER;
    argsMockTempSensorBadReq["za"] = "warudo";
    argsMockTempSensorNotFound["id"] = "giogia";
    mockTemperatureHandler = new MockTemperatureHandler({mockTempSensor});
}

void post_mock_temperature_handler() {
    delete mockTempSensor;
}

void check_temp_value_is_correct(OperationHandlerResult r, float min, float max) {
    TEST_ASSERT_EQUAL(HttpStatus::OK, r.code());
    float c = r.content().asFloat();
    TEST_ASSERT_TRUE(c >= min && c <= max);
}

void test_mock_temperature_handler_success(OperationHandler* h) {
    check_temp_value_is_correct(
        h -> handle(argsMockTempSensor),
        0,
        MOCK_MAX_TEMPERATURE_CELSIUS
    );
    argsMockTempSensor["unit"] = "f";
    check_temp_value_is_correct(
        h -> handle(argsMockTempSensor),
        Temperature::fromCToF(0),
        Temperature::fromCToF(MOCK_MAX_TEMPERATURE_CELSIUS)
    );
    argsMockTempSensor["unit"] = "k";
    check_temp_value_is_correct(
        h -> handle(argsMockTempSensor),
        Temperature::fromCToK(0),
        Temperature::fromCToK(MOCK_MAX_TEMPERATURE_CELSIUS)
    );
    argsMockTempSensor["unit"] = "c";
    check_temp_value_is_correct(
        h -> handle(argsMockTempSensor),
        0,
        MOCK_MAX_TEMPERATURE_CELSIUS
    );
}

void test_mock_temperature_handler_not_found(OperationHandler* h) {
    OperationHandlerResult r = h -> handle(argsMockTempSensorNotFound);
    TEST_ASSERT_EQUAL(HttpStatus::NotFound, r.code());
    TEST_ASSERT_EQUAL_STRING(
        phrase(ContentResult::ResourceNotFound).c_str(),
        r.content().asCString()
    );
}

void test_mock_temperature_handler_bad_req(OperationHandler* h) {
    OperationHandlerResult r = h -> handle(argsMockTempSensorBadReq);
    TEST_ASSERT_EQUAL(HttpStatus::BadRequest, r.code());
    TEST_ASSERT_EQUAL_STRING(
        phrase(ContentResult::BadRequest).c_str(),
        r.content().asCString()
    );
}

void test_mock_temperature_handler_handle_using_handler(OperationHandler* h) {
    test_mock_temperature_handler_success(h);
    test_mock_temperature_handler_not_found(h);
    test_mock_temperature_handler_bad_req(h);
}

#include "../modules/MockTemperatureModelTest.h"

void test_mock_temperature_handler_handle() {
    test_mock_temperature_handler_handle_using_handler(mockTemperatureHandler);
}

void test_MockTemperatureHandler() {
    setup_mock_temperature_handler();
    RUN_TEST(test_mock_temperature_handler_handle);
    test_MockTemperatureModule({mockTempSensor});
    post_mock_temperature_handler();
}

#endif // MOCK_TEMPERATURE_HANDLER_TEST_H