#ifndef BRITTANY_MOCK_TEMPERATURE_MODULE_H
#define BRITTANY_MOCK_TEMPERATURE_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"
#include "mock-temperature-sensor/hw/MockTemperatureSensorHw.h"
#include "mock-temperature-sensor/operation-handler/MockTemperatureHandler.h"
#include "modules/ComponentModule.h"
#include "modules/ModuleNames.h"

class MockTemperatureModule : public ComponentModule<MockTemperatureSensorHw> {

public:

    MockTemperatureModule(std::list<MockTemperatureSensorHw*> components)
    : ComponentModule<MockTemperatureSensorHw>(module_as_string(ModuleNames::Temperature), components) {
        _handlers.push_back(new MockTemperatureHandler(components));
    };

};

#endif //BRITTANY_MOCK_TEMPERATURE_MODULE_H