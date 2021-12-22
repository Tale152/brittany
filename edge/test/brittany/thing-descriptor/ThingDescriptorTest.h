#include <unity.h>
#include "json/json.h"

#define TD_IP_TEST "127.0.0.1"
#define TD_PORT_TEST 80

Edge* tdEdge;

Json::Value thingDescriptor;

void contains_context() {
    TEST_ASSERT_TRUE(thingDescriptor.isMember("@context"));
    TEST_ASSERT_EQUAL_STRING(
        "https://www.w3.org/2019/wot/td/v1",
        thingDescriptor["@context"].asCString()
    );
}

void contains_td_security() {
    TEST_ASSERT_TRUE(thingDescriptor.isMember("security"));
    TEST_ASSERT_TRUE(thingDescriptor["security"].isArray());
    TEST_ASSERT_EQUAL_STRING("no_sec", thingDescriptor["security"][0].asCString());
}

void contains_td_security_definitions() {
    TEST_ASSERT_TRUE(thingDescriptor.isMember("securityDefinitions"));
    TEST_ASSERT_TRUE(thingDescriptor["securityDefinitions"].isMember("no_sec"));
    Json::Value nosec = thingDescriptor["securityDefinitions"]["no_sec"];
    TEST_ASSERT_TRUE(nosec.isMember("scheme"));
    TEST_ASSERT_EQUAL_STRING("nosec", nosec["scheme"].asCString());
    TEST_ASSERT_TRUE(nosec.isMember("in"));
    TEST_ASSERT_EQUAL_STRING("header", nosec["in"].asCString());
}

void contains_id_and_title() {
    TEST_ASSERT_TRUE(thingDescriptor.isMember("id"));
    std::string expectedId = std::string("http://") + TD_IP_TEST + ":" + std::to_string(TD_PORT_TEST);
    TEST_ASSERT_EQUAL_STRING(expectedId.c_str(), thingDescriptor["id"].asCString());
    TEST_ASSERT_TRUE(thingDescriptor.isMember("title"));
}

void contains_all_elements() {
    thingDescriptor = tdEdge -> thingDescriptor(TD_IP_TEST, TD_PORT_TEST);
    RUN_TEST(contains_context);
    RUN_TEST(contains_id_and_title);
    RUN_TEST(contains_td_security_definitions);
    RUN_TEST(contains_td_security);
}

void test_ThingDescriptor(Edge* edge) {
    tdEdge = edge;
    contains_all_elements();
}
