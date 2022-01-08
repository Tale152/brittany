#include <unity.h>
#include "operation-handler/OperationHandlerResultTest.h"
#include "operation-handler/OperationHandlerTest.h"
#include "operation-handler/MockDigitalLightHandlersTest.h"
#include "operation-handler/util/ValueReturnedResultTest.h"
#include "hw/ComponentHwTest.h"
#include "hw/OnePinTest.h"
#include "hw/MockDigitalLightHwTest.h"
#include "hw/MockTempHumSensorHwTest.h"
#include "modules/MockDigitalLightModuleTest.h"
#include "edge/EdgeTest.h"
#include "edge/ThingDescriptorTest.h"
#include "utilTest.h"

void test_hw() {
    test_ComponentHw(); //ComponentHwTest
    test_OnePin(); //OnePinTest
    test_MockDigitalLightHw(); //MockDigitalLightHwTest
    test_MockTempHumSensorHwTest(); //MockTempHumSensorHwTest
}

void test_operation_handler() {
    test_OperationHandlerResult(); //OperationHandlerResultTest
    test_OperationHandler(); //OperationHandlerTest
    test_MockDigitalLightHandlersTest(); //MockDigitalLightHandlersTest
    test_ValueReturnedResultTest(); //ValueReturnedResultTest
}

void test_modules() {
    test_ComponentModuleTest(); //ModuleTest
}

void test_edge() {
    test_Edge(); //EdgeTest
    test_ThingDescriptor(); //ThingDescriptorTest
}

int main() {
    UNITY_BEGIN();
    test_hw();
    test_operation_handler();
    test_util();
    test_modules();
    test_edge();
    UNITY_END();
}