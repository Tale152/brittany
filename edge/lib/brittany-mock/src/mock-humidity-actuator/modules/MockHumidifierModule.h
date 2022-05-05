#ifndef BRITTANY_MOCK_HUMIDIFIER_MODULE_H
#define BRITTANY_MOCK_HUMIDIFIER_MODULE_H

#include <list>
#include "operation-handler/interfaces/components/TurnOffSwitchableHandler.h"
#include "operation-handler/interfaces/components/TurnOnSwitchableHandler.h"
#include "operation-handler/interfaces/components/IsOnSwitchableHandler.h"
#include "mock-switchable/hw/MockSwitchableHw.h"
#include "modules/ComponentModule.h"
#include "modules/ModuleNames.h"

class MockHumidifierModule : public ComponentModule<MockSwitchableHw> {

public:

    MockHumidifierModule(std::list<MockSwitchableHw*> components)
    : ComponentModule<MockSwitchableHw>(module_as_string(ModuleNames::Humidity), components) {
        _handlers.push_back(
            new TurnOnSwitchableHandler<MockSwitchableHw>(
               "humidifyOn",
               components
            )
        );
        _handlers.push_back(
            new TurnOffSwitchableHandler<MockSwitchableHw>(
               "humidifyOff",
               components
            )
        );
        _handlers.push_back(
            new IsOnSwitchableHandler<MockSwitchableHw>(
               "isHumidifyOn",
               components
            )
        );
    };

};

#endif //BRITTANY_MOCK_HUMIDIFIER_MODULE_H