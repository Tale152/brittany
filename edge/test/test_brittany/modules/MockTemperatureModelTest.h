#ifndef MOCK_TEMPERATURE_MODULE_TEST_H
#define MOCK_TEMPERATURE_MODULE_TEST_H

#include <list>
#include <unity.h>
#include "mock-temperature-sensor/modules/MockTemperatureModule.h"
#include "../operation-handler/MockTemperatureHandlerTest.h"

MockTemperatureModule* mockTemperatureModule; 

void setup_temperature_module_test(std::list<MockTemperatureSensorHw*> components) {
    mockTemperatureModule = new MockTemperatureModule(components);
}

void post_temperature_module_test() {
    delete mockTemperatureModule;
}

void test_temperature_module_name() {
    TEST_ASSERT_EQUAL_STRING(
        module_as_string(ModuleNames::Temperature).c_str(),
        mockTemperatureModule -> name().c_str()
    );
}

void test_temperature_module_components() {
    std::list<ComponentHw> comps = mockTemperatureModule -> components();
    TEST_ASSERT_EQUAL(1, comps.size());
    TEST_ASSERT_EQUAL_STRING(MOCK_TEMPERATURE_SENSOR_NAME_IN_HANDLER, comps.front().id().c_str());
}

void test_temperature_module_get_handlers() {
    std::list<OperationHandler*> handlers = mockTemperatureModule -> handlers();
    TEST_ASSERT_EQUAL(1, handlers.size());
    test_mock_temperature_handler_handle_using_handler(handlers.front());
}

void test_MockTemperatureModule(std::list<MockTemperatureSensorHw*> components) {
    setup_temperature_module_test(components);
    RUN_TEST(test_temperature_module_name);
    RUN_TEST(test_temperature_module_components);
    RUN_TEST(test_temperature_module_get_handlers);
    post_temperature_module_test();
}

#endif // MOCK_TEMPERATURE_MODULE_TEST_H