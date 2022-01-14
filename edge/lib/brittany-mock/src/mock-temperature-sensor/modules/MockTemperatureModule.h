#ifndef BRITTANY_MOCK_TEMPERATURE_MODULE_H
#define BRITTANY_MOCK_TEMPERATURE_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"
#include "mock-temperature-sensor/hw/MockTemperatureSensorHw.h"
#include "mock-temperature-sensor/operation-handler/MockTemperatureHandler.h"
#include "modules/ComponentModule.h"
#include "modules/ModuleNames.h"

#define MOCK_TEMPERATURE_HANDLER_NAME "temperature"

class MockTemperatureModule : public ComponentModule<MockTemperatureSensorHw> {

public:

    MockTemperatureModule(std::list<MockTemperatureSensorHw*> components)
    : ComponentModule<MockTemperatureSensorHw>(module_as_string(ModuleNames::Temperature), components) {
        _handlers.push_back(
            new MockTemperatureHandler(
                MOCK_TEMPERATURE_HANDLER_NAME,
                components
            )
        );
    };

};

#endif //BRITTANY_MOCK_TEMPERATURE_MODULE_H