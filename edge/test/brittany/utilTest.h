#include <unity.h>
#include <list>
#include "hw/ComponentHw.h"
#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "util.h"

#define UTIL_TEST_RANDOM_ATTEMPT 100
#define COMPONENT_0_NAME "name0"
#define COMPONENT_1_NAME "name1"
#define COMPONENT_2_NAME "name2"

ComponentHw* component0;
ComponentHw* component1;
MockDigitalLightHw* component2;
std::list<ComponentHw*> list;
std::list<MockDigitalLightHw*> list_of_light;

void setup_util_test() {
    component0 = new ComponentHw(COMPONENT_0_NAME);
    component1 = new ComponentHw(COMPONENT_1_NAME);
    component2 = new MockDigitalLightHw(COMPONENT_2_NAME);
    list.push_front(component0);
    list.push_front(component1);
    list.push_front(component2);
    list_of_light.push_front(component2);
}

void post_util_test() {
    delete component0, component1, component2;
}

void test_util_find_by_id() {
    TEST_ASSERT_EQUAL(component0, find_by_id(list, COMPONENT_0_NAME).value());
    TEST_ASSERT_EQUAL(component1, find_by_id(list, COMPONENT_1_NAME).value());
    TEST_ASSERT_EQUAL(component2, (MockDigitalLightHw*)find_by_id(list, COMPONENT_2_NAME).value());
    TEST_ASSERT_EQUAL(component2, find_by_id(list_of_light, COMPONENT_2_NAME).value());
    TEST_ASSERT_FALSE(find_by_id(list, "the game").has_value());
}

void test_util_random() {
    TEST_ASSERT_EQUAL(1, random(1,1));
    TEST_ASSERT_EQUAL(2, random(2,2));
    int min = 0;
    int max = 20;
    for(int i = 0; i <= UTIL_TEST_RANDOM_ATTEMPT; i++) {
        int r = random(min, max);
        TEST_ASSERT_TRUE(r >= min && r<= max);
    }
}

void test_util() {
    setup_util_test();
    RUN_TEST(test_util_find_by_id);
    RUN_TEST(test_util_random);
    post_util_test();
}
