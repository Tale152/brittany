#ifndef BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
#define BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/components/IsOnSwitchableHandler.h"
#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "operation-handler/OperationHandlerResult.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"
#include <optional>

class MockIsOnDigitalLightHandler: public IsOnSwitchableHandler<MockDigitalLightHw> {

public:

    MockIsOnDigitalLightHandler(std::list<MockDigitalLightHw*> components)
        : IsOnSwitchableHandler<MockDigitalLightHw>("isOn", components) {
    };
};

#endif //BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
