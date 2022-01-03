#ifndef BRITTANY_MOCK_DIGITAL_LIGHT_MODULE_H
#define BRITTANY_MOCK_DIGITAL_LIGHT_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"
#include "modules/ComponentModule.h"
#include "modules/ComponentModule.cpp"
#include "../hw/MockDigitalLightHw.h"
#include "../operation-handler/digital-light/MockIsOnDigitalLightHandler.h"
#include "../operation-handler/digital-light/MockTurnOffDigitalLightHandler.h"
#include "../operation-handler/digital-light/MockTurnOnDigitalLightHandler.h"

#define MOCK_IS_ON_HANDLER_MODULE_NAME "isOn"
#define MOCK_TURN_ON_HANDLER_MODULE_NAME "turnOn"
#define MOCK_TURN_OFF_HANDLER_MODULE_NAME "turnOff"

class MockDigitalLightModule : public ComponentModule<MockDigitalLightHw> {

public:

    MockDigitalLightModule(std::string name, std::list<MockDigitalLightHw*> components): ComponentModule<MockDigitalLightHw>(name, components) {
        _handlers.push_back(
            new MockIsOnDigitalLightHandler(
                MOCK_IS_ON_HANDLER_MODULE_NAME,
                as_route(MOCK_IS_ON_HANDLER_MODULE_NAME),
                components
            )
        );
        _handlers.push_back(
            new MockTurnOnDigitalLightHandler(
                MOCK_TURN_ON_HANDLER_MODULE_NAME,
                as_route(MOCK_TURN_ON_HANDLER_MODULE_NAME),
                components
            )
        );  
        _handlers.push_back(
            new MockTurnOffDigitalLightHandler(
                MOCK_TURN_OFF_HANDLER_MODULE_NAME,
                as_route(MOCK_TURN_OFF_HANDLER_MODULE_NAME),
                components
            )
        );
    };

};

#endif //BRITTANY_MOCK_DIGITAL_LIGHT_MODULE_H