#include <unity.h>
#include "../mock/operation-handler/digital-light/MockTurnOffDigitalLightHandler.h"
#include "../mock/operation-handler/digital-light/MockTurnOnDigitalLightHandler.h"
#include "HttpStatusCodes_C++.h"

#define LIGHT_0_NAME "light0"
#define LIGHT_0_PIN 10
#define LIGHT_1_NAME "light1"
#define LIGHT_1_PIN 11

#define MOCK_TURN_OFF_LIGHT_PATH "/turnOff"
#define MOCK_TURN_ON_LIGHT_PATH "/turnOn"

MockDigitalLightHw* light0;
MockDigitalLightHw* light1;
std::list<MockDigitalLightHw*> light_list;
MockTurnOffDigitalLightHandler* turnOffDigitalLightHandler;
MockTurnOnDigitalLightHandler* turnOnDigitalLightHandler;

void setup_mock_light_handler_test() {
    light0 = new MockDigitalLightHw(LIGHT_0_NAME, LIGHT_0_PIN);
    light1 = new MockDigitalLightHw(LIGHT_1_NAME, LIGHT_1_PIN);
    light_list.push_front(light0);
    light_list.push_front(light1);
    turnOffDigitalLightHandler = new MockTurnOffDigitalLightHandler(MOCK_TURN_OFF_LIGHT_PATH, light_list);
    turnOnDigitalLightHandler = new MockTurnOnDigitalLightHandler(MOCK_TURN_ON_LIGHT_PATH, light_list);
}

void check_result_is_ok(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::OK, result.code());
    TEST_ASSERT_EQUAL_STRING("Ok.", result.content().asString().c_str());
}

void check_result_is_fail(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::NotFound, result.code());
    TEST_ASSERT_EQUAL_STRING("Operation failed.", result.content().asString().c_str());
}

void test_MockTurnOffDigitalLightHandler() {
    TEST_ASSERT_EQUAL_STRING(MOCK_TURN_OFF_LIGHT_PATH, turnOffDigitalLightHandler->path().c_str());
    check_result_is_ok(
        turnOffDigitalLightHandler->handle(Json::Value(LIGHT_0_NAME))
    );
    check_result_is_ok(
        turnOffDigitalLightHandler->handle(Json::Value(LIGHT_1_NAME))
    );
    check_result_is_fail(
        turnOffDigitalLightHandler->handle(Json::Value("the game"))
    );
}

void test_MockTurnOnDigitalLightHandler(){
    TEST_ASSERT_EQUAL_STRING(MOCK_TURN_ON_LIGHT_PATH, turnOnDigitalLightHandler->path().c_str());
    check_result_is_ok(
        turnOnDigitalLightHandler->handle(Json::Value(LIGHT_0_NAME))
    );
    check_result_is_ok(
        turnOnDigitalLightHandler->handle(Json::Value(LIGHT_1_NAME))
    );
    check_result_is_fail(
        turnOnDigitalLightHandler->handle(Json::Value("the game"))
    );
}

void test_MockDigitalLightHandlersTest() {
    setup_mock_light_handler_test();
    RUN_TEST(test_MockTurnOffDigitalLightHandler);
    RUN_TEST(test_MockTurnOnDigitalLightHandler);
}
