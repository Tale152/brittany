#ifndef BRITTANY_MOCK_DEHUMIDIFIER_MODULE_H
#define BRITTANY_MOCK_DEHUMIDIFIER_MODULE_H

#include <list>
#include "operation-handler/interfaces/components/TurnOffSwitchableHandler.h"
#include "operation-handler/interfaces/components/TurnOnSwitchableHandler.h"
#include "operation-handler/interfaces/components/IsOnSwitchableHandler.h"
#include "mock-switchable/hw/MockSwitchableHw.h"
#include "modules/ComponentModule.h"
#include "modules/ModuleNames.h"

class MockDehumidifierModule : public ComponentModule<MockSwitchableHw> {

public:

    MockDehumidifierModule(std::list<MockSwitchableHw*> components)
    : ComponentModule<MockSwitchableHw>(module_as_string(ModuleNames::Humidity), components) {
        _handlers.push_back(
            new TurnOnSwitchableHandler<MockSwitchableHw>(
               "dehumidifyOn",
               components
            )
        );
        _handlers.push_back(
            new TurnOffSwitchableHandler<MockSwitchableHw>(
               "dehumidifyOff",
               components
            )
        );
        _handlers.push_back(
            new IsOnSwitchableHandler<MockSwitchableHw>(
               "isDehumidifyOn",
               components
            )
        );
    };

};

#endif //BRITTANY_MOCK_DEHUMIDIFIER_MODULE_H