#include <unity.h>
#include "ComponentHwTest.h"
#include "OnePinTest.h"
#include "MockDigitalLightHwTest.h"

int main() {
    UNITY_BEGIN();
    test_ComponentHw(); //ComponentHwTest
    test_OnePin(); //OnePinTest
    test_MockDigitalLightHw(); //MockDigitalLightHwTest
    UNITY_END();
}