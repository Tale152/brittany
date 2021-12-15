#include <unity.h>
#include "operation-handler/OperationHandlerResultTest.h"
#include "operation-handler/OperationHandlerTest.h"
#include "operation-handler/MockDigitalLightHandlersTest.h"
#include "hw/ComponentHwTest.h"
#include "hw/OnePinTest.h"
#include "hw/MockDigitalLightHwTest.h"
#include "modules/ModuleTest.h"
#include "utilTest.h"

void test_hw() {
    test_ComponentHw(); //ComponentHwTest
    test_OnePin(); //OnePinTest
    test_MockDigitalLightHw(); //MockDigitalLightHwTest
}

void test_operation_handler() {
    test_OperationHandlerResult(); //OperationHandlerResultTest
    test_OperationHandler(); //OperationHandlerTest
    test_MockDigitalLightHandlersTest(); //MockDigitalLightHandlersTest
}

void test_modules(){
    test_ModuleTest(); //ModuleTest
}

int main() {
    UNITY_BEGIN();
    test_hw();
    test_operation_handler();
    test_util();
    test_modules();
    UNITY_END();
}