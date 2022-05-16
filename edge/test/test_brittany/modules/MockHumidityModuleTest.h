#ifndef MOCK_HUMIDITY_MODULE_TEST_H
#define MOCK_HUMIDITY_MODULE_TEST_H

#include <list>
#include <unity.h>
#include "mock-humidity-sensor/modules/MockHumidityModule.h"
#include "../operation-handler/MockHumidityHandlerTest.h"

MockHumidityModule* mockHumidityModule; 

void setup_humidity_module_test(std::list<MockHumiditySensorHw*> components) {
    mockHumidityModule = new MockHumidityModule(components);
}

void post_humidity_module_test() {
    delete mockHumidityModule;
}

void test_humidity_module_name() {
    TEST_ASSERT_EQUAL_STRING(
        module_as_string(ModuleNames::Humidity).c_str(),
        mockHumidityModule -> name().c_str()
    );
}

void test_humidity_module_components() {
    std::list<ComponentHw> comps = mockHumidityModule -> components();
    TEST_ASSERT_EQUAL(1, comps.size());
    TEST_ASSERT_EQUAL_STRING(MOCK_HUMIDITY_SENSOR_NAME_IN_HANDLER, comps.front().id().c_str());
}

void test_humidity_module_get_handlers() {
    std::list<OperationHandler*> handlers = mockHumidityModule -> handlers();
    TEST_ASSERT_EQUAL(1, handlers.size());
    test_mock_humidity_handler_handle_using_handler(handlers.front());
}

void test_MockHumidityModule(std::list<MockHumiditySensorHw*> components) {
    setup_humidity_module_test(components);
    RUN_TEST(test_humidity_module_name);
    RUN_TEST(test_humidity_module_components);
    RUN_TEST(test_humidity_module_get_handlers);
    post_humidity_module_test();
}

#endif // MOCK_HUMIDITY_MODULE_TEST_H