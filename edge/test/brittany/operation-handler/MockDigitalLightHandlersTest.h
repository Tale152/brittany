#include <unity.h>
#include "../mock/operation-handler/digital-light/MockTurnOffDigitalLightHandler.h"
#include "../mock/operation-handler/digital-light/MockTurnOnDigitalLightHandler.h"
#include "../mock/operation-handler/digital-light/MockIsOnDigitalLightHandler.h"
#include "HttpStatusCodes_C++.h"

#define LIGHT_0_NAME "light0"
#define LIGHT_0_PIN 10
#define LIGHT_1_NAME "light1"
#define LIGHT_1_PIN 11

#define MOCK_TURN_OFF_LIGHT_PATH "/turnOff"
#define MOCK_TURN_ON_LIGHT_PATH "/turnOn"
#define MOCK_IS_ON_LIGHT_PATH "/isOn"

MockDigitalLightHw* light0;
MockDigitalLightHw* light1;
std::list<MockDigitalLightHw*> light_list;
MockTurnOffDigitalLightHandler* turnOffDigitalLightHandler;
MockTurnOnDigitalLightHandler* turnOnDigitalLightHandler;
MockIsOnDigitalLightHandler* isOnDigitalLightHandler;

void setup_mock_light_handler_test() {
    light0 = new MockDigitalLightHw(LIGHT_0_NAME, LIGHT_0_PIN);
    light1 = new MockDigitalLightHw(LIGHT_1_NAME, LIGHT_1_PIN);
    light_list.push_front(light0);
    light_list.push_front(light1);
    turnOffDigitalLightHandler = new MockTurnOffDigitalLightHandler(MOCK_TURN_OFF_LIGHT_PATH, light_list);
    turnOnDigitalLightHandler = new MockTurnOnDigitalLightHandler(MOCK_TURN_ON_LIGHT_PATH, light_list);
    isOnDigitalLightHandler = new MockIsOnDigitalLightHandler(MOCK_IS_ON_LIGHT_PATH, light_list);
}

void check_result_is_ok(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::OK, result.code());
    TEST_ASSERT_EQUAL_STRING("Ok.", result.content().asString().c_str());
}

void check_result_is_fail(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::NotFound, result.code());
    TEST_ASSERT_EQUAL_STRING("Operation failed.", result.content().asString().c_str());
}

//TEST
void test_mock_turn_off_digital_light_handler() {
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

//TEST
void test_mock_turn_on_digital_light_handler(){
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

void light_state_check(OperationHandlerResult result, bool isOn) {
    TEST_ASSERT_EQUAL(HttpStatus::OK, result.code());
    TEST_ASSERT_EQUAL(isOn, result.content().asBool());
}

void is_on_handler_state_must_be(bool isOn) {
    TEST_ASSERT_EQUAL_STRING(MOCK_IS_ON_LIGHT_PATH, isOnDigitalLightHandler->path().c_str());
    light_state_check(isOnDigitalLightHandler->handle(Json::Value(LIGHT_0_NAME)), isOn);
    light_state_check(isOnDigitalLightHandler->handle(Json::Value(LIGHT_1_NAME)), isOn);
    check_result_is_fail(isOnDigitalLightHandler->handle(Json::Value("the game")));
}

//TEST
void test_mock_turn_is_on_digital_light_handler() {
    is_on_handler_state_must_be(true);
}

//TEST
void test_mock_turn_is_off_digital_light_handler() {
    is_on_handler_state_must_be(false);
}

void test_MockDigitalLightHandlersTest() {
    setup_mock_light_handler_test();
    RUN_TEST(test_mock_turn_off_digital_light_handler);
    RUN_TEST(test_mock_turn_is_off_digital_light_handler);
    RUN_TEST(test_mock_turn_on_digital_light_handler);
    RUN_TEST(test_mock_turn_is_on_digital_light_handler);
}
