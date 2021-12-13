#ifndef BRITTANY_COMPONENT_HW_TEST_H
#define BRITTANY_COMPONENT_HW_TEST_H

#include <unity.h>
#include "ComponentHw.h"

#define HW_ID "component"

ComponentHw mockComponent = ComponentHw(HW_ID);

void test_get_component_hw_id() {
    TEST_ASSERT_EQUAL_STRING(mockComponent.id().c_str(), HW_ID);
}

void test_ComponentHw() {
    RUN_TEST(test_get_component_hw_id);
}

#endif //BRITTANY_COMPONENT_HW_TEST_H