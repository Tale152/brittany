/* * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <unity.h>
#include "json/json.h"
#include "edge/Edge.h"
#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "mock-digital-light/modules/MockDigitalLightModule.h"

#define EDGE_MOCK_TITLE_TD "MockEdge"
#define MOCK_LIGHT_TD_0_ID "0"
#define MOCK_LIGHT_TD_1_ID "1"
#define MOCK_LIGHT_TD_2_ID "2"

#define TD_IP_TEST "127.0.0.1"
#define TD_PORT_TEST 80

MockDigitalLightHw* mockLight0;
MockDigitalLightHw* mockLight1;
MockDigitalLightHw* mockLight2;

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
    TEST_ASSERT_EQUAL_STRING(EDGE_MOCK_TITLE_TD, thingDescriptor["title"].asCString());
}

void contains_modules() {
    TEST_ASSERT_TRUE(thingDescriptor.isMember("modules"));
    Json::Value modulesArray = thingDescriptor["modules"];
    TEST_ASSERT_TRUE(modulesArray.isArray());
    Json::Value moduleObj = modulesArray[0];
    TEST_ASSERT_TRUE(moduleObj.isMember("module"));
    TEST_ASSERT_EQUAL_STRING(module_as_string(ModuleNames::Light).c_str(), moduleObj["module"].asCString());
    TEST_ASSERT_TRUE(moduleObj.isMember("components"));
    Json::Value moduleComponents = moduleObj["components"];
    TEST_ASSERT_TRUE(moduleComponents.isArray());
    TEST_ASSERT_EQUAL_STRING(MOCK_LIGHT_TD_0_ID, moduleComponents[0].asCString());
    TEST_ASSERT_EQUAL_STRING(MOCK_LIGHT_TD_1_ID, moduleComponents[1].asCString());
    TEST_ASSERT_EQUAL_STRING(MOCK_LIGHT_TD_2_ID, moduleComponents[2].asCString());
}

void check_additional_actions(Json::Value action) {
    TEST_ASSERT_TRUE(action.isMember("output"));
    TEST_ASSERT_TRUE(action["output"].isMember("type"));
    TEST_ASSERT_EQUAL_STRING("string", action["output"]["type"].asCString());
}

void check_additional_properties(Json::Value property) {
    TEST_ASSERT_TRUE(property.isMember("type"));
    TEST_ASSERT_EQUAL_STRING("boolean", property["type"].asCString());
}

void check_additional_events(Json::Value event) {

}

void check_actions_and_properties(Json::Value object, std::string names[], int size, OperationType type) {
    for(int i = 0; i < size; i++) {
        for(std::string c : tdComponents) {
            Json::Value name = object[names[i] + "-" + c];
            TEST_ASSERT_TRUE(name.isMember("module"));
            TEST_ASSERT_EQUAL_STRING(module_as_string(ModuleNames::Light).c_str(), name["module"].asCString());
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
            switch (type) {
            case OperationType::ACTION:
                check_additional_actions(name);
                break;
            case OperationType::PROPERTY:
                check_additional_properties(name);
                break;
            case OperationType::EVENT:
                check_additional_events(name);
                break;
            default:
                break;
            }
        }
        //TODO TEST WITH A SINGLE COMPONENT, AS THE ACTION AND PROPERTY NAME CHANGES
    }
}

void contains_properties() {
    TEST_ASSERT_TRUE(thingDescriptor.isMember("properties"));
    Json::Value properties = thingDescriptor["properties"];
    std::string propertiesName[1] = {"isOn"};
    check_actions_and_properties(properties, propertiesName, 1, OperationType::PROPERTY);
}

void contains_actions() {
    TEST_ASSERT_TRUE(thingDescriptor.isMember("actions"));
    Json::Value actions = thingDescriptor["actions"];
    std::string actionNames[2] = {"turnOn", "turnOff"};
    check_actions_and_properties(actions, actionNames, 2, OperationType::ACTION);
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
    mockLight0 = new MockDigitalLightHw(MOCK_LIGHT_TD_0_ID);
    mockLight1 = new MockDigitalLightHw(MOCK_LIGHT_TD_1_ID);
    mockLight2 = new MockDigitalLightHw(MOCK_LIGHT_TD_2_ID);
    tdEdge = new Edge(EDGE_MOCK_TITLE_TD, 
        std::list<Module*>({
            new MockDigitalLightModule(
                std::list({mockLight0, mockLight1})
            ),
            new MockDigitalLightModule(
                std::list({mockLight2})
            )}
        )
    );
}

void post_thing_descriptor_test() {
    delete mockLight0, mockLight1, mockLight2, tdEdge;
}

void test_ThingDescriptor() {
    setup_thing_descriptor_test();
    contains_all_elements();
    post_thing_descriptor_test();
}
