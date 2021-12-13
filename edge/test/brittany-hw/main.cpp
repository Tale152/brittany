#include <unity.h>
#include "ComponentHwTest.h"
#include "OnePinTest.h"

int main() {
    UNITY_BEGIN();
    test_ComponentHw(); //ComponentHwTest
    test_OnePin(); //OnePinTest
    UNITY_END();
}