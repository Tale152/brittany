#include <list>
#include <unity.h>
#include "mock-humidity-sensor/operation-handler/MockHumidityHandler.h"
#include "mock-humidity-sensor/hw/MockHumiditySensorHw.h"

#define MOCK_HUMIDITY_SENSOR_NAME_IN_HANDLER "sensor"
#define MOCK_HUMIDITY_HANDLER_NAME "humidity"

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
    std::list<MockHumiditySensorHw*> list = {mockHumSensor};
    mockHumidityHandler = new MockHumidityHandler(
        MOCK_HUMIDITY_HANDLER_NAME,
        as_route(MOCK_HUMIDITY_HANDLER_NAME),
        list
    );
}

void post_mock_humidity_handler() {
    delete mockHumSensor;
}

void test_mock_humidity_handler_success() {
    OperationHandlerResult r = mockHumidityHandler -> handle(argsMockHumSensor);
    TEST_ASSERT_EQUAL(HttpStatus::OK, r.code());
    float c = r.content().asFloat();
    TEST_ASSERT_TRUE(c >= 0 && c <= MOCK_MAX_HUMIDITY);
}

void test_mock_humidity_handler_not_found() {
    OperationHandlerResult r = mockHumidityHandler -> handle(argsMockHumSensorNotFound);
    TEST_ASSERT_EQUAL(HttpStatus::NotFound, r.code());
    TEST_ASSERT_EQUAL_STRING(
        phrase(ContentResult::ResourceNotFound).c_str(),
        r.content().asCString()
    );
}

void test_mock_humidity_handler_bad_req() {
    OperationHandlerResult r = mockHumidityHandler -> handle(argsMockHumSensorBadReq);
    TEST_ASSERT_EQUAL(HttpStatus::BadRequest, r.code());
    TEST_ASSERT_EQUAL_STRING(
        phrase(ContentResult::BadRequest).c_str(),
        r.content().asCString()
    );
}

void test_mock_humidity_handler_handle() {
    test_mock_humidity_handler_success();
    test_mock_humidity_handler_not_found();
    test_mock_humidity_handler_bad_req();
}

void test_MockHumidityHandler() {
    setup_mock_humidity_handler();
    RUN_TEST(test_mock_humidity_handler_handle);
    post_mock_humidity_handler();
}