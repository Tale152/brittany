#include <unity.h>
#include "operation-handler/MockOperationHandler.h"

#define OPERATION_HANDLER_NAME "Operation"
#define OPERATION_HANDLER_PATH "/operation"
#define OPERATION_HANDLER_TYPE OperationType::ACTION

MockOperationHandler mockOperationHandler = MockOperationHandler(
    OPERATION_HANDLER_NAME,
    OPERATION_HANDLER_PATH,
    OPERATION_HANDLER_TYPE
);

void test_operation_handler_name() {
    TEST_ASSERT_EQUAL_STRING(OPERATION_HANDLER_NAME, mockOperationHandler.name().c_str());
}

void test_operation_handler_path() {
    TEST_ASSERT_EQUAL_STRING(OPERATION_HANDLER_PATH, mockOperationHandler.path().c_str());
}

void test_operation_handler_type() {
    TEST_ASSERT_EQUAL(OPERATION_HANDLER_TYPE, mockOperationHandler.operationType());
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
    RUN_TEST(test_operation_handler_type);
}
