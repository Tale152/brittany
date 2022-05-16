#include <unity.h>
#include "operation-handler/OperationHandlerResultTest.h"
#include "operation-handler/OperationHandlerTest.h"
#include "operation-handler/MockDigitalLightHandlersTest.h"
#include "operation-handler/MockHumidityHandlerTest.h"
#include "operation-handler/MockTemperatureHandlerTest.h"
#include "operation-handler/util/ValueReturnedResultTest.h"
#include "operation-handler/util/ValueReturnedResultFactoryTest.h"
#include "operation-handler/types/TypeTest.h"
#include "hw/ComponentHwTest.h"
#include "hw/OnePinTest.h"
#include "hw/MockSwitchableHwTest.h"
#include "hw/MockDigitalLightHwTest.h"
#include "hw/MockTemperatureSensorHwTest.h"
#include "hw/MockHumiditySensorHwTest.h"
#include "modules/MockDigitalLightModuleTest.h"
#include "modules/ModuleNamesTest.h"
#include "edge/EdgeTest.h"
#include "edge/ThingDescriptorTest.h"
#include "utilTest.h"

void test_hw() {
    test_ComponentHw(); //ComponentHwTest
    test_OnePin(); //OnePinTest
    test_MockDigitalLightHw(); //MockDigitalLightHwTest
    test_MockSwitchableHwTest(); //MockSwitchableHwTest
    test_MockTemperatureSensorHwTest(); //MockTemperatureSensoreHwTest
    test_MockHumiditySensorHwTest(); //MockTemperatureSensoreHwTest
}

void test_operation_handler() {
    test_OperationHandlerResult(); //OperationHandlerResultTest
    test_OperationHandler(); //OperationHandlerTest
    test_MockDigitalLightHandlersTest(); //MockDigitalLightHandlersTest
    test_MockHumidityHandler(); //MockHumidityHandlerTest
    test_MockTemperatureHandler(); //MockTemperatureHandlerTest
    test_ValueReturnedResultTest(); //ValueReturnedResultTest
    test_ValueReturnedResultFactoryTest(); //ValueReturnedResultFactoryTest
    test_Type(); //TypeTest
}

void test_modules() {
    test_ComponentModuleTest(); //ModuleTest
    test_ModuleNamesTest(); //ModuleNamesTest
}

void test_edge() {
    test_Edge(); //EdgeTest
    test_ThingDescriptor(); //ThingDescriptorTest
}

void f () {
    TEST_ASSERT_TRUE(true);
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