#include <unity.h>
#include "json/json.h"
#include "edge/Edge.h"
#include "hw/MockDigitalLightHw.h"
#include "modules/MockDigitalLightModule.h"

#define MOCK_MODULE_TD_NAME "light-module"
#define MOCK_LIGHT_TD_0_ID "0"
#define MOCK_LIGHT_TD_1_ID "1"

#define TD_IP_TEST "127.0.0.1"
#define TD_PORT_TEST 80

MockDigitalLightHw* mockLight0;
MockDigitalLightHw* mockLight1;

Edge* tdEdge;

Json::Value thingDescriptor;

std::string tdComponents[2] = {MOCK_LIGHT_TD_0_ID, MOCK_LIGHT_TD_1_ID};

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
    TEST_ASSERT_EQUAL_STRING(MOCK_MODULE_TD_NAME, moduleObj["module"].asCString());
    TEST_ASSERT_TRUE(moduleObj.isMember("components"));
    Json::Value moduleComponents = moduleObj["components"];
    TEST_ASSERT_TRUE(moduleComponents.isArray());
    TEST_ASSERT_EQUAL_STRING(MOCK_LIGHT_TD_0_ID, moduleComponents[0].asCString());
    TEST_ASSERT_EQUAL_STRING(MOCK_LIGHT_TD_1_ID, moduleComponents[1].asCString());
}

void check_actions_and_properties(Json::Value object, std::string names[], int size) {
    for(int i = 0; i < size; i++) {
        for(std::string c : tdComponents) {
            Json::Value name = object[names[i] + "-" + c];
            TEST_ASSERT_TRUE(name.isMember("module"));
            TEST_ASSERT_EQUAL_STRING(MOCK_MODULE_TD_NAME, name["module"].asCString());
            TEST_ASSERT_TRUE(name.isMember("forms"));
            Json::Value forms = name["forms"];
            TEST_ASSERT_TRUE(forms.isArray());
            TEST_ASSERT_TRUE(forms[0].isMember("href"));
            TEST_ASSERT_TRUE(forms[0].isMember("contentType"));
            //link check
            TEST_ASSERT_EQUAL_STRING(
                (std::string("http://") + TD_IP_TEST + ":" + std::to_string(TD_PORT_TEST) + "/" + names[i] + "?id=" + c).c_str(),
                forms[0]["href"].asCString()
            );
            TEST_ASSERT_EQUAL_STRING("application/json", forms[0]["contentType"].asCString());
        }
        
    }
}

void contains_properties() {
    TEST_ASSERT_TRUE(thingDescriptor.isMember("properties"));
    Json::Value properties = thingDescriptor["properties"];
    std::string propertiesName[1] = {"isOn"};
    check_actions_and_properties(properties, propertiesName, 1);
}

void contains_actions() {
    TEST_ASSERT_TRUE(thingDescriptor.isMember("actions"));
    Json::Value actions = thingDescriptor["actions"];
    std::string actionNames[2] = {"turnOn", "turnOff"};
    check_actions_and_properties(actions, actionNames, 2);
}

void contains_all_elements() {
    thingDescriptor = tdEdge -> thingDescriptor(TD_IP_TEST, TD_PORT_TEST);
    RUN_TEST(contains_context);
    RUN_TEST(contains_id_and_title);
    RUN_TEST(contains_td_security_definitions);
    RUN_TEST(contains_td_security);
    RUN_TEST(contains_modules);
    RUN_TEST(contains_properties);
    RUN_TEST(contains_actions);
}

void setup_thing_descriptor_test() { 
    mockLight0 = new MockDigitalLightHw(MOCK_LIGHT_TD_0_ID, 0);
    mockLight1 = new MockDigitalLightHw(MOCK_LIGHT_TD_1_ID, 1);
    tdEdge = new Edge(std::list<Module*>({
        new MockDigitalLightModule(
            MOCK_MODULE_TD_NAME,
            std::list({mockLight0, mockLight1})
        )}
    ));
}

void post_thing_descriptor_test() {
    delete mockLight0, mockLight1, tdEdge;
}

void test_ThingDescriptor() {
    setup_thing_descriptor_test();
    contains_all_elements();
    post_thing_descriptor_test();
}
