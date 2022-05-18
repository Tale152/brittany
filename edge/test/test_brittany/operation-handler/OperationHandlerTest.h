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
