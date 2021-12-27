#include <unity.h>
#include "edge/Edge.h"
#include "modules/MockDigitalLightModule.h"
#include "modules/MockModule.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"

#define EDGE_MOCK_MODULE_NAME "mock-module"
#define EDGE_MOCK_DIGITAL_LIGHT_MODULE_NAME "light-module"

#define MOCK_LIGHT_IN_EDGE_NAME "light"
#define MOCK_LIGHT_IN_EDGE_PIN 5
#define TESTING_EXECUTE_ATTEMPT 10

#define INCREMENT_VALUE_TEST 6

MockDigitalLightHw* mockLightInEdge;
std::list<MockDigitalLightHw*> mockDigitalLights;

void setup_test_edge() {
    mockLightInEdge = new MockDigitalLightHw(
        MOCK_LIGHT_IN_EDGE_NAME,
        MOCK_LIGHT_IN_EDGE_PIN
    );
    mockDigitalLights.push_back(mockLightInEdge);
}

void post_test_edge() {
    delete mockLightInEdge;
}

void test_edge_result_fail(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::NotFound, result.code());
    TEST_ASSERT_EQUAL_STRING(
        phrase(ContentResult::ResourceNotFound).c_str(),
        result.content().asString().c_str()
    );
}

void test_edge_execute_fail(Edge* edge) {
    for(int i = 0; i < TESTING_EXECUTE_ATTEMPT; i++) {
        test_edge_result_fail(edge -> execute("/"+ i, Json::Value()));
    }
}

void check_edge_result_code_is_ok(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::OK, result.code());
}

void test_edge_execute_working(Edge* edge) {
    auto result0 = edge -> execute(
        as_route(OPERATION_HANDLER_IN_MOCK_MODULE_NAME),
        Json::Value(INCREMENT_VALUE_TEST)
    );
    check_edge_result_code_is_ok(result0);
    TEST_ASSERT_EQUAL(INCREMENT_VALUE_TEST, result0.content().asInt());
    Json::Value args;
    args["id"] = MOCK_LIGHT_IN_EDGE_NAME;
    auto result1 = edge -> execute(as_route(MOCK_TURN_ON_HANDLER_MODULE_NAME), args);
    check_edge_result_code_is_ok(result1);
    TEST_ASSERT_EQUAL_STRING(phrase(ContentResult::Ok).c_str(), result1.content().asString().c_str());
    auto result = edge -> execute(as_route(MOCK_IS_ON_HANDLER_MODULE_NAME), args);
    check_edge_result_code_is_ok(result);
    TEST_ASSERT_TRUE(result.content().asBool());
}

//TEST
void test_edge_empty() {
    Edge* edge = new Edge(std::list<Module*>({}));
    test_edge_execute_fail(edge);
    delete edge;
}

//TEST
void test_edge_list() {
    Edge* edge = new Edge(std::list<Module*>({
        new MockModule(EDGE_MOCK_MODULE_NAME),
        new MockDigitalLightModule(EDGE_MOCK_DIGITAL_LIGHT_MODULE_NAME, mockDigitalLights)}
    ));
    test_edge_execute_working(edge);
    delete edge;
}

void test_Edge() {
    setup_test_edge();
    RUN_TEST(test_edge_empty);
    RUN_TEST(test_edge_list);
    post_test_edge();
}
