#include <unity.h>
#include "operation-handler/digital-light/MockTurnOffDigitalLightHandler.h"
#include "operation-handler/digital-light/MockTurnOnDigitalLightHandler.h"
#include "operation-handler/digital-light/MockIsOnDigitalLightHandler.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"

#define LIGHT_0_NAME "light0"
#define LIGHT_0_PIN 10
#define LIGHT_1_NAME "light1"
#define LIGHT_1_PIN 11

#define MOCK_TURN_OFF_LIGHT_NAME "turnOff"
#define MOCK_TURN_ON_LIGHT_NAME "turnOn"
#define MOCK_IS_ON_LIGHT_NAME "isOn"

MockDigitalLightHw* light0;
MockDigitalLightHw* light1;
std::list<MockDigitalLightHw*> light_list;
MockTurnOffDigitalLightHandler* turnOffDigitalLightHandler;
MockTurnOnDigitalLightHandler* turnOnDigitalLightHandler;
MockIsOnDigitalLightHandler* isOnDigitalLightHandler;

Json::Value args0;
Json::Value args1;
Json::Value argsFail;

void setup_mock_light_handler_test() {
    light0 = new MockDigitalLightHw(LIGHT_0_NAME, LIGHT_0_PIN);
    light1 = new MockDigitalLightHw(LIGHT_1_NAME, LIGHT_1_PIN);
    light_list.push_front(light0);
    light_list.push_front(light1);
    turnOffDigitalLightHandler = new MockTurnOffDigitalLightHandler(
        MOCK_TURN_OFF_LIGHT_NAME,
        as_route(MOCK_TURN_OFF_LIGHT_NAME),
        light_list
    );
    turnOnDigitalLightHandler = new MockTurnOnDigitalLightHandler(
        MOCK_TURN_ON_LIGHT_NAME,
        as_route(MOCK_TURN_ON_LIGHT_NAME),
        light_list
    );
    isOnDigitalLightHandler = new MockIsOnDigitalLightHandler(
        MOCK_IS_ON_LIGHT_NAME,
        as_route(MOCK_IS_ON_LIGHT_NAME),
        light_list
    );
    args0["id"] = LIGHT_0_NAME;
    args1["id"] = LIGHT_1_NAME;
    argsFail["id"] = "the game";
}

void post_mock_light_handler_test () {
    delete light0, light1, turnOffDigitalLightHandler, turnOnDigitalLightHandler, isOnDigitalLightHandler;
}

void check_result_is_ok(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::OK, result.code());
    TEST_ASSERT_EQUAL_STRING("Ok.", result.content().asCString());
}

void check_result_is_fail(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::NotFound, result.code());
    TEST_ASSERT_EQUAL_STRING("Operation failed.", result.content().asCString());
}

//TEST
void test_mock_turn_off_digital_light_handler() {
    TEST_ASSERT_EQUAL_STRING(
        MOCK_TURN_OFF_LIGHT_NAME,
        turnOffDigitalLightHandler -> name().c_str()
    );
    TEST_ASSERT_EQUAL_STRING(
        as_route(MOCK_TURN_OFF_LIGHT_NAME).c_str(),
        turnOffDigitalLightHandler -> path().c_str()
    );
    check_result_is_ok(
        turnOffDigitalLightHandler->handle(args0)
    );
    check_result_is_ok(
        turnOffDigitalLightHandler->handle(args1)
    );
    check_result_is_fail(
        turnOffDigitalLightHandler->handle(argsFail)
    );
}

//TEST
void test_mock_turn_on_digital_light_handler(){
    TEST_ASSERT_EQUAL_STRING(
        MOCK_TURN_ON_LIGHT_NAME,
        turnOnDigitalLightHandler -> name().c_str()
    );
    TEST_ASSERT_EQUAL_STRING(
        as_route(MOCK_TURN_ON_LIGHT_NAME).c_str(),
        turnOnDigitalLightHandler -> path().c_str()
    );
    check_result_is_ok(
        turnOnDigitalLightHandler->handle(args0)
    );
    check_result_is_ok(
        turnOnDigitalLightHandler->handle(args1)
    );
    check_result_is_fail(
        turnOnDigitalLightHandler->handle(argsFail)
    );
}

void light_state_check(OperationHandlerResult result, bool isOn) {
    TEST_ASSERT_EQUAL(HttpStatus::OK, result.code());
    TEST_ASSERT_EQUAL(isOn, result.content().asBool());
}

void is_on_handler_state_must_be(bool isOn) {
    TEST_ASSERT_EQUAL_STRING(
        MOCK_IS_ON_LIGHT_NAME,
        isOnDigitalLightHandler -> name().c_str()
    );
    TEST_ASSERT_EQUAL_STRING(
        as_route(MOCK_IS_ON_LIGHT_NAME).c_str(),
        isOnDigitalLightHandler -> path().c_str()
    );

    light_state_check(isOnDigitalLightHandler->handle(args0), isOn);
    light_state_check(isOnDigitalLightHandler->handle(args1), isOn);
    check_result_is_fail(isOnDigitalLightHandler->handle(argsFail));
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
    post_mock_light_handler_test();
}
