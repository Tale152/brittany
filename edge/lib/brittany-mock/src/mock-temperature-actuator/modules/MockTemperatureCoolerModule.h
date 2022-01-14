#ifndef BRITTANY_MOCK_TEMPERATURE_COOLER_MODULE_H
#define BRITTANY_MOCK_TEMPERATURE_COOLER_MODULE_H

#include <list>

#include "operation-handler/interfaces/components/TurnOffSwitchableHandler.h"
#include "operation-handler/interfaces/components/TurnOnSwitchableHandler.h"
#include "operation-handler/interfaces/components/IsOnSwitchableHandler.h"
#include "mock-switchable/hw/MockSwitchableHw.h"
#include "modules/ComponentModule.h"
#include "modules/ModuleNames.h"

class MockTemperatureCoolerModule : public ComponentModule<MockSwitchableHw> {

public:

    MockTemperatureCoolerModule(std::list<MockSwitchableHw*> components)
    : ComponentModule<MockSwitchableHw>(module_as_string(ModuleNames::Temperature), components) {
        _handlers.push_back(
            new TurnOnSwitchableHandler<MockSwitchableHw>(
               "coolOn",
               components
            )
        );
        _handlers.push_back(
            new TurnOffSwitchableHandler<MockSwitchableHw>(
               "coolOff",
               components
            )
        );
        _handlers.push_back(
            new IsOnSwitchableHandler<MockSwitchableHw>(
               "isCoolOn",
               components
            )
        );
    };

};

#endif //BRITTANY_MOCK_TEMPERATURE_COOLER_MODULE_H