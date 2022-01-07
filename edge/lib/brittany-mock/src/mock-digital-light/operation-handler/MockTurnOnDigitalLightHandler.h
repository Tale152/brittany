#ifndef BRITTANY_MOCK_TURN_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
#define BRITTANY_MOCK_TURN_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/TurnOnHandlerInterface.h"
#include "operation-handler/interfaces/TurnOnHandlerInterface.cpp"
#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "operation-handler/OperationHandlerResult.h"
#include "util.h"

class MockTurnOnDigitalLightHandler : public TurnOnHandlerInterface {

public:

    MockTurnOnDigitalLightHandler(
        std::string name,
        std::string path,
        std::list<MockDigitalLightHw*> components
    ): TurnOnHandlerInterface(name, path) {
         _components = components;
    };

private:

    bool turnOn(std::string id) {
        std::optional<MockDigitalLightHw*> oc = find_by_id(_components, id);
        if(oc.has_value()) {
            oc.value() -> on();
            return true;
        } else {
            return false;
        }
    };

    std::list<MockDigitalLightHw*> _components;

};

#endif //BRITTANY_MOCK_TURN_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
