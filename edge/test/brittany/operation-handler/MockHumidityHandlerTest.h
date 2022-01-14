#ifndef MOCK_HUMIDITY_HANDLER_TEST_H
#define MOCK_HUMIDITY_HANDLER_TEST_H

#include <list>
#include <unity.h>
#include "mock-humidity-sensor/operation-handler/MockHumidityHandler.h"
#include "mock-humidity-sensor/hw/MockHumiditySensorHw.h"


#define MOCK_HUMIDITY_SENSOR_NAME_IN_HANDLER "sensor"

MockHumidityHandler* mockHumidityHandler;
MockHumiditySensorHw* mockHumSensor;

Json::Value argsMockHumSensor;
Json::Value argsMockHumSensorBadReq;
Json::Value argsMockHumSensorNotFound;

void setup_mock_humidity_handler() {
    mockHumSensor = new MockHumiditySensorHw(MOCK_HUMIDITY_SENSOR_NAME_IN_HANDLER);
    argsMockHumSensor["id"] = MOCK_HUMIDITY_SENSOR_NAME_IN_HANDLER;
    argsMockHumSensorBadReq["za"] = "warudo";
    argsMockHumSensorNotFound["id"] = "giogia";
    mockHumidityHandler = new MockHumidityHandler({mockHumSensor});
}

void post_mock_humidity_handler() {
    delete mockHumSensor;
}

void test_mock_humidity_handler_success(OperationHandler* h) {
    OperationHandlerResult r = h -> handle(argsMockHumSensor);
    TEST_ASSERT_EQUAL(HttpStatus::OK, r.code());
    float c = r.content().asFloat();
    TEST_ASSERT_TRUE(c >= 0 && c <= MOCK_MAX_HUMIDITY);
}

void test_mock_humidity_handler_not_found(OperationHandler* h) {
    OperationHandlerResult r = h -> handle(argsMockHumSensorNotFound);
    TEST_ASSERT_EQUAL(HttpStatus::NotFound, r.code());
    TEST_ASSERT_EQUAL_STRING(
        phrase(ContentResult::ResourceNotFound).c_str(),
        r.content().asCString()
    );
}

void test_mock_humidity_handler_bad_req(OperationHandler* h) {
    OperationHandlerResult r = h -> handle(argsMockHumSensorBadReq);
    TEST_ASSERT_EQUAL(HttpStatus::BadRequest, r.code());
    TEST_ASSERT_EQUAL_STRING(
        phrase(ContentResult::BadRequest).c_str(),
        r.content().asCString()
    );
}

void test_mock_humidity_handler_handle_using_handler(OperationHandler* h) {
    test_mock_humidity_handler_success(h);
    test_mock_humidity_handler_not_found(h);
    test_mock_humidity_handler_bad_req(h);
}

#include "../modules/MockHumidityModuleTest.h"

void test_mock_humidity_handler_handle() {
    test_mock_humidity_handler_handle_using_handler(mockHumidityHandler);
}

void test_MockHumidityHandler() {
    setup_mock_humidity_handler();
    RUN_TEST(test_mock_humidity_handler_handle);
    test_MockHumidityModule({mockHumSensor});
    post_mock_humidity_handler();
}

#endif // MOCK_HUMIDITY_HANDLER_TEST_H