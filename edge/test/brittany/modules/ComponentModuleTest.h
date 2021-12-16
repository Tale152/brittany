#include <list>
#include <unity.h>
#include "operation-handler/OperationHandler.h"
#include "operation-handler/OperationHandlerResult.h"
#include "../mock/operation-handler/MockOperationHandler.h"
#include "../mock/hw/MockDigitalLightHw.h"
#include "../mock/modules/MockComponentModule.h"
#include "modules/Module.h"

#define MOCK_LIGHT_IN_MODULE_NAME_0 "light0"
#define MOCK_LIGHT_IN_MODULE_NAME_1 "light1"

#define MOCK_LIGHT_IN_MODULE_PIN_0 1
#define MOCK_LIGHT_IN_MODULE_PIN_1 2

MockDigitalLightHw* lightInModule0;
MockDigitalLightHw* lightInModule1;
MockComponentModule* moduleTest;
std::list<MockDigitalLightHw*> components;

std::list<std::string> lightNames = {MOCK_LIGHT_IN_MODULE_NAME_0, MOCK_LIGHT_IN_MODULE_NAME_1};

void setup_module_test() {
    lightInModule0 = new MockDigitalLightHw(MOCK_LIGHT_IN_MODULE_NAME_0, MOCK_LIGHT_IN_MODULE_PIN_0);
    lightInModule1 = new MockDigitalLightHw(MOCK_LIGHT_IN_MODULE_NAME_1, MOCK_LIGHT_IN_MODULE_PIN_1);
    components.push_back(lightInModule0);
    components.push_back(lightInModule1);
    moduleTest = new MockComponentModule(components);
}

void post_module_test() {
    delete lightInModule0, lightInModule1, moduleTest;
}

void execute_on_each_component(OperationHandler* handler, void (*f)(OperationHandler*, std::string)) {
    for(std::string l : lightNames){
        (*f)(handler, l);
    }
}

void check_handler_path(OperationHandler* handler, std::string handler_path) {
    TEST_ASSERT_EQUAL_STRING(handler_path.c_str(), handler->path().c_str());
}

void check_handler_code_is_ok(OperationHandlerResult result) {
    TEST_ASSERT_EQUAL(HttpStatus::OK, result.code());
}

void test_turn_on_turn_off_handler_in_module(OperationHandler* handler, std::string handler_path, std::string component_name) {
    check_handler_path(handler, handler_path);
    OperationHandlerResult result = handler->handle(Json::Value(component_name));
    check_handler_code_is_ok(result);
    TEST_ASSERT_EQUAL_STRING("Ok.", result.content().asString().c_str());
}

void test_is_on_is_off_handler_in_module(OperationHandler* handler, std::string component_name, bool isOn) {
    check_handler_path(handler, MOCK_IS_ON_HANDLER_MODULE_PATH);
    OperationHandlerResult result = handler->handle(Json::Value(component_name));
    check_handler_code_is_ok(result);
    TEST_ASSERT_EQUAL(isOn, result.content().asBool());
}

void test_turn_on_handler_in_module(OperationHandler* handler, std::string component_name) {
    test_turn_on_turn_off_handler_in_module(handler, MOCK_TURN_ON_HANDLER_MODULE_PATH, component_name);
}

void test_turn_off_handler_in_module(OperationHandler* handler, std::string component_name) {
    test_turn_on_turn_off_handler_in_module(handler, MOCK_TURN_OFF_HANDLER_MODULE_PATH, component_name);
}

void test_is_off_handler_in_module(OperationHandler* handler, std::string component_name) {
    test_is_on_is_off_handler_in_module(handler, component_name, false);
}

void test_is_on_handler_in_module(OperationHandler* handler, std::string component_name) {
    test_is_on_is_off_handler_in_module(handler, component_name, true);
}

void test_module_get_handlers(){
    std::list<OperationHandler*> handlersList = moduleTest -> handlers();
    TEST_ASSERT_EQUAL(3, handlersList.size());
    OperationHandler* isOnHandler = handlersList.front();
    execute_on_each_component(isOnHandler, test_is_off_handler_in_module);
    handlersList.pop_front();
    OperationHandler* turnOnHandler = handlersList.front();
    execute_on_each_component(turnOnHandler, test_turn_on_handler_in_module);
    execute_on_each_component(isOnHandler, test_is_on_handler_in_module);
    handlersList.pop_front();
    OperationHandler* turnOffHandler = handlersList.front();
    execute_on_each_component(turnOffHandler, test_turn_off_handler_in_module);
    execute_on_each_component(isOnHandler, test_is_off_handler_in_module);
    handlersList.pop_front();
    TEST_ASSERT_EQUAL(0, handlersList.size());
}

void test_ComponentModuleTest() {
    setup_module_test();
    RUN_TEST(test_module_get_handlers);
    post_module_test();
}