#include <unity.h>
#include "mock-switchable/hw/MockSwitchableHw.h"

#define MOCK_SWITCHABLE_HW_ID "switch"

MockSwitchableHw mockSwitchableHw = MockSwitchableHw(MOCK_SWITCHABLE_HW_ID);

void mock_switchable_hw_is_on_must_be(bool must_be) {
    if(must_be) {
        TEST_ASSERT_TRUE(mockSwitchableHw.isOn());
    } else {
        TEST_ASSERT_FALSE(mockSwitchableHw.isOn());
    }
}

void test_mock_switchable_hw_is_off() {
    mock_switchable_hw_is_on_must_be(false);
}

void test_mock_switchable_hw_is_on() {
    mock_switchable_hw_is_on_must_be(true);
}

void test_MockSwitchableHwTest() {
    RUN_TEST(test_mock_switchable_hw_is_off);
    mockSwitchableHw.on();
    RUN_TEST(test_mock_switchable_hw_is_on);
    mockSwitchableHw.off();
    RUN_TEST(test_mock_switchable_hw_is_off);
}
