#ifndef BRITTANY_ONE_PIN_TEST_H
#define BRITTANY_ONE_PIN_TEST_H

#include <unity.h>
#include "feature/OnePin.h"

#define SINGLE_PIN_PIN 10

OnePin mockOnePin = OnePin(SINGLE_PIN_PIN);

void test_get_one_pin_pin() {
    TEST_ASSERT_EQUAL(mockOnePin.pin(), SINGLE_PIN_PIN);
}

void test_OnePin(){
    RUN_TEST(test_get_one_pin_pin);
}

#endif //BRITTANY_ONE_PIN_TEST_H