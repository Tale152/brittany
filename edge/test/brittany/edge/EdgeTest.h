#include <unity.h>
#include <list>
#include "edge/Edge.h"
#include "operation-handler/MockOperationHandler.h"

#define MOCK_OPERATION_HANDLER_IN_EDGE_PATH_0 "/path0"
#define MOCK_OPERATION_HANDLER_IN_EDGE_PATH_1 "/path1"
#define INCREMENT_VALUE_IN_EDGE 5

MockOperationHandler* operationHandlerInEdge0;
MockOperationHandler* operationHandlerInEdge1;
Edge* edgeTest;

void setup_test_edge() {
    operationHandlerInEdge0 = new MockOperationHandler(MOCK_OPERATION_HANDLER_IN_EDGE_PATH_0);
    operationHandlerInEdge1 = new MockOperationHandler(MOCK_OPERATION_HANDLER_IN_EDGE_PATH_1);
    edgeTest = new Edge(std::list<OperationHandler*>({operationHandlerInEdge0, operationHandlerInEdge1}));
}

void post_test_edge() {
    delete operationHandlerInEdge0, operationHandlerInEdge1, edgeTest;
}

void test_handler_success(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::OK, result.code());
    TEST_ASSERT_EQUAL(INCREMENT_VALUE_IN_EDGE, result.content().asInt());
}

void test_handler_fail(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::NotFound, result.code());
    TEST_ASSERT_EQUAL_STRING("The requested resource does not exist.", result.content().asString().c_str());
}

void test_execute() {
    test_handler_success(
        edgeTest -> execute(MOCK_OPERATION_HANDLER_IN_EDGE_PATH_0, Json::Value(INCREMENT_VALUE_IN_EDGE))
    );
    test_handler_success(
        edgeTest -> execute(MOCK_OPERATION_HANDLER_IN_EDGE_PATH_1, Json::Value(INCREMENT_VALUE_IN_EDGE))
    );
    test_handler_fail(
        edgeTest -> execute("/ippopotamo", Json::Value(1))
    );
}

void test_thing_descriptor() {
    //TODO
}

void test_Edge() {
    setup_test_edge();
    RUN_TEST(test_execute);
    RUN_TEST(test_thing_descriptor);
    post_test_edge();
}