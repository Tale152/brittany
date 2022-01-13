#ifndef BRITTANY_MOCK_TURN_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
#define BRITTANY_MOCK_TURN_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/components/TurnOnSwitchableHandler.h"
#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "operation-handler/OperationHandlerResult.h"
#include "util.h"

class MockTurnOnDigitalLightHandler: public TurnOnSwitchableHandler<MockDigitalLightHw> {

public:

    MockTurnOnDigitalLightHandler(
        std::string name,
        std::string path,
        std::list<MockDigitalLightHw*> components
    ): TurnOnSwitchableHandler<MockDigitalLightHw>(
        name,
        path,
        components
    ) {

    }
};

#endif //BRITTANY_MOCK_TURN_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
