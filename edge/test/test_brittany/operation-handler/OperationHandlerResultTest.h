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
#include <json/json.h>
#include <json/value.h>
#include "operation-handler/OperationHandlerResult.h"
#include "HttpStatusCodes_C++.h"

#define RESULT_CODE HttpStatus::NotFound

Json::Value content;
OperationHandlerResult* result;

void test_operation_handler_result_code() {
    TEST_ASSERT_EQUAL(RESULT_CODE, result -> code());
}

void test_operation_handler_result_content() {
    Json::Value json_content = result -> content();
    TEST_ASSERT_EQUAL(1, json_content.get("one", Json::Value()).asInt());
    TEST_ASSERT_TRUE(json_content.get("happy", Json::Value()).asBool());
    TEST_ASSERT_TRUE(json_content.get("two", Json::Value().isNull()));
}

void setup_operation_handler_result_test(){
    content["one"] = 1;
    content["happy"] = true;
    result = new OperationHandlerResult(RESULT_CODE, content);
}


void post_operation_handler_result_test(){
    delete result;
}

void test_OperationHandlerResult() {
    setup_operation_handler_result_test();
    RUN_TEST(test_operation_handler_result_code);
    RUN_TEST(test_operation_handler_result_content);
}
