#ifndef BRITTANY_MOCK_TURN_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
#define BRITTANY_MOCK_TURN_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include "operation-handler/interfaces/components/TurnOnSwitchableHandler.h"
#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "operation-handler/OperationHandlerResult.h"
#include "util.h"

class MockTurnOnDigitalLightHandler: public TurnOnSwitchableHandler<MockDigitalLightHw> {

public:

    MockTurnOnDigitalLightHandler(std::list<MockDigitalLightHw*> components)
        : TurnOnSwitchableHandler<MockDigitalLightHw>("turnOn", components) {

    }
};

#endif //BRITTANY_MOCK_TURN_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
