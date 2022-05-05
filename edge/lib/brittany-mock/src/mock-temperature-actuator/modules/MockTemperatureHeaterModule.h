#ifndef BRITTANY_MOCK_TEMPERATURE_HEATER_MODULE_H
#define BRITTANY_MOCK_TEMPERATURE_HEATER_MODULE_H

#include <list>

#include "operation-handler/interfaces/components/TurnOffSwitchableHandler.h"
#include "operation-handler/interfaces/components/TurnOnSwitchableHandler.h"
#include "operation-handler/interfaces/components/IsOnSwitchableHandler.h"
#include "mock-switchable/hw/MockSwitchableHw.h"
#include "modules/ComponentModule.h"
#include "modules/ModuleNames.h"

class MockTemperatureHeaterModule : public ComponentModule<MockSwitchableHw> {

public:

    MockTemperatureHeaterModule(std::list<MockSwitchableHw*> components)
    : ComponentModule<MockSwitchableHw>(module_as_string(ModuleNames::Temperature), components) {
        _handlers.push_back(
            new TurnOnSwitchableHandler<MockSwitchableHw>(
               "heatOn",
               components
            )
        );
        _handlers.push_back(
            new TurnOffSwitchableHandler<MockSwitchableHw>(
               "heatOff",
               components
            )
        );
        _handlers.push_back(
            new IsOnSwitchableHandler<MockSwitchableHw>(
               "isHeatOn",
               components
            )
        );
    };

};

#endif //BRITTANY_MOCK_TEMPERATURE_HEATER_MODULE_H