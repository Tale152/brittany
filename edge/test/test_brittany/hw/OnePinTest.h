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
#include "hw/feature/OnePin.h"

#define SINGLE_PIN_PIN 10

OnePin mockOnePin = OnePin(SINGLE_PIN_PIN);

void test_get_one_pin_pin() {
    TEST_ASSERT_EQUAL(mockOnePin.pin(), SINGLE_PIN_PIN);
}

void test_OnePin() {
    RUN_TEST(test_get_one_pin_pin);
}
