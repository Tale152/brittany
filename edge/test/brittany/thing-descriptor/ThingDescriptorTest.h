#include <unity.h>
#include "json/json.h"
#include "edge/Edge.h"

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

void contains_modules() {
    TEST_ASSERT_TRUE(thingDescriptor.isMember("modules"));
    Json::Value modulesArray = thingDescriptor["modules"];
    TEST_ASSERT_TRUE(modulesArray.isArray());
    Json::Value moduleObj = modulesArray[0];
    TEST_ASSERT_TRUE(moduleObj.isMember("module"));
    TEST_ASSERT_EQUAL_STRING("light-module", moduleObj["module"].asCString());
    TEST_ASSERT_TRUE(moduleObj.isMember("components"));
    Json::Value moduleComponents = moduleObj["components"];
    TEST_ASSERT_TRUE(moduleComponents.isArray());
    TEST_ASSERT_EQUAL_STRING("light", moduleComponents[0].asCString());
}

void contains_actions() {
    TEST_ASSERT_TRUE(thingDescriptor.isMember("actions"));
    Json::Value actions = thingDescriptor["actions"];
    std::string actionNames[3] = {"turnOn", "turnOff", "isOn"};
    for(std::string n : actionNames) {
        Json::Value action = actions[n];
        TEST_ASSERT_TRUE(action.isMember("module"));
        TEST_ASSERT_EQUAL_STRING("light-module", action["module"].asCString());
        TEST_ASSERT_TRUE(action.isMember("forms"));
        Json::Value forms = action["forms"];
        TEST_ASSERT_TRUE(forms.isArray());
        TEST_ASSERT_TRUE(forms[0].isMember("href"));
        TEST_ASSERT_TRUE(forms[0].isMember("contentType"));
        TEST_ASSERT_EQUAL_STRING(
            (std::string("http://") + TD_IP_TEST + ":" + std::to_string(TD_PORT_TEST) + "/" + n).c_str(),
            forms[0]["href"].asCString()
        );
        TEST_ASSERT_EQUAL_STRING("application/json", forms[0]["contentType"].asCString());
    }
    
}

void contains_all_elements() {
    thingDescriptor = tdEdge -> thingDescriptor(TD_IP_TEST, TD_PORT_TEST);
    RUN_TEST(contains_context);
    RUN_TEST(contains_id_and_title);
    RUN_TEST(contains_td_security_definitions);
    RUN_TEST(contains_td_security);
    RUN_TEST(contains_modules);
    RUN_TEST(contains_actions);
}

void test_ThingDescriptor(Edge* edge) {
    tdEdge = edge;
    contains_all_elements();
}
