#include <unity.h>
#include "edge/Edge.h"
#include "mock-digital-light/modules/MockDigitalLightModule.h"
#include "mock/modules/MockModule.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"
#include <algorithm>

#define EDGE_MOCK_TITLE "MockEdge"
#define EDGE_MOCK_MODULE_NAME "mock-module"

#define MOCK_LIGHT_IN_EDGE_NAME "light"
#define MOCK_LIGHT_IN_EDGE_PIN 5
#define TESTING_EXECUTE_ATTEMPT 10

#define INCREMENT_VALUE_TEST 6

MockDigitalLightHw* mockLightInEdge;
std::list<MockDigitalLightHw*> mockDigitalLights;

void test_string_element_is_in_list(std::list<std::string> list, std::string string) {
    bool found = std::find(list.begin(), list.end(), string) != list.end();
    TEST_ASSERT_TRUE(found);
}

void test_light_module_available_path(Edge* edge) {
    test_string_element_is_in_list(
        edge -> availablePaths(),
        "/isOn"
    );
    test_string_element_is_in_list(
        edge -> availablePaths(),
        "/turnOff"
    );
    test_string_element_is_in_list(
        edge -> availablePaths(),
        "/turnOn"
    );
}

void test_mock_module_available_path(Edge* edge) {
    test_string_element_is_in_list(
        edge -> availablePaths(),
        as_route(OPERATION_HANDLER_IN_MOCK_MODULE_NAME)
    );
}

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

void test_edge_title(Edge* edge) {
    TEST_ASSERT_EQUAL_STRING(EDGE_MOCK_TITLE, edge -> title().c_str());
}

void test_edge_result_fail(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::NotFound, result.code());
    TEST_ASSERT_EQUAL_STRING(
        phrase(ContentResult::ResourceNotFound).c_str(),
        result.content().asCString()
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

void test_edge_available_path(Edge* edge) {
    std::list<std::string> paths = edge -> availablePaths();

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
    auto result1 = edge -> execute("/turnOn", args);
    check_edge_result_code_is_ok(result1);
    TEST_ASSERT_EQUAL_STRING(phrase(ContentResult::Ok).c_str(), result1.content().asCString());
    auto result = edge -> execute("/isOn", args);
    check_edge_result_code_is_ok(result);
    TEST_ASSERT_TRUE(result.content().asBool());
}

//TEST
void test_edge_empty() {
    Edge* edge = new Edge(EDGE_MOCK_TITLE, std::list<Module*>({}));
    test_edge_execute_fail(edge);
    TEST_ASSERT_EQUAL(0, edge ->availablePaths().size());
    delete edge;
}

//TEST
void test_edge_list() {
    Edge* edge = new Edge(EDGE_MOCK_TITLE,
        std::list<Module*>({
            new MockModule(EDGE_MOCK_MODULE_NAME),
            new MockDigitalLightModule(mockDigitalLights)
        })
    );
    test_edge_title(edge);
    test_mock_module_available_path(edge);
    test_light_module_available_path(edge);
    TEST_ASSERT_EQUAL(4, edge ->availablePaths().size());
    test_edge_execute_working(edge);
    delete edge;
}

void test_Edge() {
    setup_test_edge();
    RUN_TEST(test_edge_empty);
    RUN_TEST(test_edge_list);
    post_test_edge();
}
