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
#include "modules/ModuleNames.h"

void test_module_as_string() {
    TEST_ASSERT_EQUAL_STRING("light", module_as_string(ModuleNames::Light).c_str());
    TEST_ASSERT_EQUAL_STRING("temperature", module_as_string(ModuleNames::Temperature).c_str());
    TEST_ASSERT_EQUAL_STRING("airHumidity", module_as_string(ModuleNames::Humidity).c_str());
    TEST_ASSERT_EQUAL_STRING("", module_as_string(ModuleNames(104131)).c_str());
}

void test_ModuleNamesTest() {
    RUN_TEST(test_module_as_string);
}