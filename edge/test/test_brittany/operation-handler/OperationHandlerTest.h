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
#include "mock/operation-handler/MockOperationHandler.h"
#include "util.h"

MockOperationHandler mockOperationHandler = MockOperationHandler();

void test_operation_handler_name() {
    TEST_ASSERT_EQUAL_STRING("value", mockOperationHandler.name().c_str());
}

void test_operation_handler_path() {
    TEST_ASSERT_EQUAL_STRING("/value", mockOperationHandler.path().c_str());
}

void test_operation_handler_operation_type() {
    TEST_ASSERT_EQUAL(OperationType::PROPERTY, mockOperationHandler.operationType());
}

void test_operation_handler_output_type() {
    TEST_ASSERT_EQUAL(Type::INTEGER, mockOperationHandler.outputType());
}

void test_operation_handler_handle() {
    for(int i = 1; i < 10; i++) {
        OperationHandlerResult result = mockOperationHandler.handle(Json::Value(1));
        TEST_ASSERT_EQUAL(HttpStatus::OK, result.code());
        TEST_ASSERT_EQUAL(i, result.content().asInt());
    }
}

void test_OperationHandler() {
    RUN_TEST(test_operation_handler_path);
    RUN_TEST(test_operation_handler_handle);
    RUN_TEST(test_operation_handler_operation_type);
    RUN_TEST(test_operation_handler_output_type);
}
