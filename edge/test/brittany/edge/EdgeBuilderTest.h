#include <unity.h>
#include "edge/Edge.h"
#include "edge/EdgeBuilder.h"
#include "modules/MockDigitalLightModule.h"
#include "modules/MockModule.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"

#define MOCK_LIGHT_IN_EDGE_BUILDER_NAME "light"
#define MOCK_LIGHT_IN_EDGE_BUILDER_PIN 5
#define TESTING_EXECUTE_ATTEMPT 10

#define INCREMENT_VALUE_TEST 6

MockDigitalLightHw* mockLightInEdgeBuilder;
std::list<MockDigitalLightHw*> mockDigitalLights;

void setup_test_edge_builder() {
    mockLightInEdgeBuilder = new MockDigitalLightHw(
        MOCK_LIGHT_IN_EDGE_BUILDER_NAME,
        MOCK_LIGHT_IN_EDGE_BUILDER_PIN
    );
    mockDigitalLights.push_back(mockLightInEdgeBuilder);
}

void post_test_edge_builder() {
    delete mockLightInEdgeBuilder;
}

void test_edge_builder_result_fail(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::NotFound, result.code());
    TEST_ASSERT_EQUAL_STRING(
        phrase(ContentResult::ResourceNotFound).c_str(),
        result.content().asString().c_str()
    );
}

void test_edge_execute_fail(Edge edge) {
    for(int i = 0; i < TESTING_EXECUTE_ATTEMPT; i++) {
        test_edge_builder_result_fail(edge.execute("/"+ i, Json::Value()));
    }
}

void check_edge_builder_result_code_is_ok(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::OK, result.code());
}

void test_edge_execute_working(Edge edge) {
    auto result0 = edge.execute(OPERATION_HANDLER_IN_MOCK_MODULE_PATH, Json::Value(INCREMENT_VALUE_TEST));
    check_edge_builder_result_code_is_ok(result0);
    TEST_ASSERT_EQUAL(INCREMENT_VALUE_TEST, result0.content().asInt());
    auto result1 = edge.execute(MOCK_TURN_ON_LIGHT_PATH, Json::Value(MOCK_LIGHT_IN_EDGE_BUILDER_NAME));
    check_edge_builder_result_code_is_ok(result1);
    TEST_ASSERT_EQUAL_STRING(phrase(ContentResult::Ok).c_str(), result1.content().asString().c_str());
    auto result = edge.execute(MOCK_IS_ON_LIGHT_PATH, Json::Value(MOCK_LIGHT_IN_EDGE_BUILDER_NAME));
    check_edge_builder_result_code_is_ok(result);
    TEST_ASSERT_TRUE(result.content().asBool());
}

//TEST
void test_edgeBuilder_empty() {
    test_edge_execute_fail(EdgeBuilder().build());
}

void execute_edge_test(Edge edge) {
    test_edge_execute_working(edge);
    test_edge_execute_fail(edge);
}

//TEST
void test_edgeBuilder_add_module() {
    EdgeBuilder builder = EdgeBuilder();
    builder.addModule(MockModule());
    builder.addModule(MockDigitalLightModule(mockDigitalLights));
    execute_edge_test(builder.build());
}

//TEST
void test_edgeBuilder_add_all_module() {
    EdgeBuilder builder = EdgeBuilder();
    builder.addAllModules(std::list<Module>({
        MockModule(),
        MockDigitalLightModule(mockDigitalLights)}
    ));
    execute_edge_test(builder.build());
}

void test_EdgeBuilder() {
    setup_test_edge_builder();
    RUN_TEST(test_edgeBuilder_empty);
    RUN_TEST(test_edgeBuilder_add_module);
    RUN_TEST(test_edgeBuilder_add_all_module);
    post_test_edge_builder();
}
