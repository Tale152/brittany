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
