#ifndef BRITTANY_MOCK_MODULE_H
#define BRITTANY_MOCK_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"
#include "modules/Module.h"
#include "modules/Module.cpp"
#include "../hw/MockDigitalLightHw.h"
#include "../operation-handler/digital-light/MockIsOnDigitalLightHandler.h"
#include "../operation-handler/digital-light/MockTurnOffDigitalLightHandler.h"
#include "../operation-handler/digital-light/MockTurnOnDigitalLightHandler.h"

#define MOCK_IS_ON_HANDLER_MODULE_PATH "/isOn"
#define MOCK_TURN_ON_HANDLER_MODULE_PATH "/turnOn"
#define MOCK_TURN_OFF_HANDLER_MODULE_PATH "/turnOff"

class MockModule : public Module<MockDigitalLightHw> {

public:

    MockModule(std::list<MockDigitalLightHw*> components): Module<MockDigitalLightHw>(components) {
        _handlers.push_back(
            new MockIsOnDigitalLightHandler(MOCK_IS_ON_HANDLER_MODULE_PATH, components)
        );
        _handlers.push_back(
            new MockTurnOnDigitalLightHandler(MOCK_TURN_ON_HANDLER_MODULE_PATH, components)
        );  
        _handlers.push_back(
            new MockTurnOffDigitalLightHandler(MOCK_TURN_OFF_HANDLER_MODULE_PATH, components)
        );
    };

};

#endif //BRITTANY_MOCK_MODULE_H