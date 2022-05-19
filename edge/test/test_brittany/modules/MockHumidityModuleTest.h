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