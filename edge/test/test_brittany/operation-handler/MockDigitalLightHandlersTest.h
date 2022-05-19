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
#include "mock-digital-light/operation-handler/MockTurnOffDigitalLightHandler.h"
#include "mock-digital-light/operation-handler/MockTurnOnDigitalLightHandler.h"
#include "mock-digital-light/operation-handler/MockIsOnDigitalLightHandler.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"

#define LIGHT_0_NAME "light0"
#define LIGHT_1_NAME "light1"

MockDigitalLightHw* light0;
MockDigitalLightHw* light1;
std::list<MockDigitalLightHw*> light_list;
MockTurnOffDigitalLightHandler* turnOffDigitalLightHandler;
MockTurnOnDigitalLightHandler* turnOnDigitalLightHandler;
MockIsOnDigitalLightHandler* isOnDigitalLightHandler;

Json::Value args0;
Json::Value args1;
Json::Value argsNotFound;
Json::Value argsBadRequest;

void setup_mock_light_handler_test() {
    light0 = new MockDigitalLightHw(LIGHT_0_NAME);
    light1 = new MockDigitalLightHw(LIGHT_1_NAME);
    light_list.push_front(light0);
    light_list.push_front(light1);
    turnOffDigitalLightHandler = new MockTurnOffDigitalLightHandler(light_list);
    turnOnDigitalLightHandler = new MockTurnOnDigitalLightHandler(light_list);
    isOnDigitalLightHandler = new MockIsOnDigitalLightHandler(light_list);
    args0["id"] = LIGHT_0_NAME;
    args1["id"] = LIGHT_1_NAME;
    argsNotFound["id"] = "the game";
    argsBadRequest["za"] = "warudo";
}

void post_mock_light_handler_test () {
    delete light0, light1, turnOffDigitalLightHandler, turnOnDigitalLightHandler, isOnDigitalLightHandler;
}

void check_result_is_ok(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::OK, result.code());
    TEST_ASSERT_EQUAL_STRING(
        phrase(ContentResult::Ok).c_str(),
        result.content().asCString()
    );
}

void check_result_is_error(OperationHandlerResult result, int code, std::string message) {
    TEST_ASSERT_EQUAL(code, result.code());
    TEST_ASSERT_EQUAL_STRING(message.c_str(), result.content().asCString());
}

void check_result_is_not_found(OperationHandlerResult result) {
    check_result_is_error(
        result,
        HttpStatus::NotFound,
        phrase(ContentResult::ResourceNotFound).c_str()
    );
}

void check_result_is_bad_request(OperationHandlerResult result) {
    check_result_is_error(
        result,
        HttpStatus::BadRequest,
        phrase(ContentResult::BadRequest).c_str()
    );
}

template <class T>
void test_handler_name_and_path(T h, std::string name) {
    TEST_ASSERT_EQUAL_STRING(name.c_str(), h -> name().c_str());
    TEST_ASSERT_EQUAL_STRING(as_route(name).c_str(), h -> path().c_str());
}

template <class T>
void test_handle_with_different_args(T h) {
    check_result_is_ok(h->handle(args0));
    check_result_is_ok(h->handle(args1));
    check_result_is_not_found(h->handle(argsNotFound));
    check_result_is_bad_request(h->handle(argsBadRequest));
}

//TEST
void test_mock_turn_off_digital_light_handler() {
    test_handler_name_and_path(turnOffDigitalLightHandler, "turnOff");
    test_handle_with_different_args(turnOffDigitalLightHandler);   
}

//TEST
void test_mock_turn_on_digital_light_handler(){
    test_handler_name_and_path(turnOnDigitalLightHandler, "turnOn");
    test_handle_with_different_args(turnOnDigitalLightHandler);
}

void light_state_check(OperationHandlerResult result, bool isOn) {
    TEST_ASSERT_EQUAL(HttpStatus::OK, result.code());
    TEST_ASSERT_EQUAL(isOn, result.content().asBool());
}

void is_on_handler_state_must_be(bool isOn) {
    test_handler_name_and_path(isOnDigitalLightHandler, "isOn");
    light_state_check(isOnDigitalLightHandler->handle(args0), isOn);
    light_state_check(isOnDigitalLightHandler->handle(args1), isOn);
    check_result_is_not_found(isOnDigitalLightHandler->handle(argsNotFound));
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
