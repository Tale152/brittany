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
               as_route("heatOn"),
               components
            )
        );
        _handlers.push_back(
            new TurnOffSwitchableHandler<MockSwitchableHw>(
               "heatOff",
               as_route("heatOff"),
               components
            )
        );
        _handlers.push_back(
            new IsOnSwitchableHandler<MockSwitchableHw>(
               "isHeatOn",
               as_route("isHeatOn"),
               components
            )
        );
    };

};

#endif //BRITTANY_MOCK_TEMPERATURE_HEATER_MODULE_H