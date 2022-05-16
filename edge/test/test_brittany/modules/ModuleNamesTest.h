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