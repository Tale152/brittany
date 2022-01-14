#ifndef BRITTANY_MOCK_TURN_OFF_DIGITAL_LIGHT_HANDLER_INTERFACE_H
#define BRITTANY_MOCK_TURN_OFF_DIGITAL_LIGHT_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include "operation-handler/interfaces/components/TurnOffSwitchableHandler.h"
#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "operation-handler/OperationHandlerResult.h"
#include "util.h"

class MockTurnOffDigitalLightHandler: public TurnOffSwitchableHandler<MockDigitalLightHw> {

public:

    MockTurnOffDigitalLightHandler(std::list<MockDigitalLightHw*> components)
        : TurnOffSwitchableHandler<MockDigitalLightHw>("turnOff", components) {

    };

};

#endif //BRITTANY_MOCK_TURN_OFF_DIGITAL_LIGHT_HANDLER_INTERFACE_H
