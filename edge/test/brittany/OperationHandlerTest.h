#ifndef BRITTANY_OPERATION_HANDLER_TEST
#define BRITTANY_OPERATION_HANDLER_TEST

#include <unity.h>
#include "mock/MockOperationHandler.h"

#define OPERATION_HANDLER_PATH "/operation"

MockOperationHandler mockOperationHandler = MockOperationHandler(OPERATION_HANDLER_PATH);

void test_operation_handler_path() {
    TEST_ASSERT_EQUAL_STRING(OPERATION_HANDLER_PATH, mockOperationHandler.path().c_str());
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
}

#endif //BRITTANY_OPERATION_HANDLER_TEST