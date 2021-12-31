#ifndef BRITTANY_MOCK_TURN_OFF_DIGITAL_LIGHT_HANDLER_INTERFACE_H
#define BRITTANY_MOCK_TURN_OFF_DIGITAL_LIGHT_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/TurnOffHandlerInterface.h"
#include "operation-handler/interfaces/TurnOffHandlerInterface.cpp"
#include "../../hw/MockDigitalLightHw.h"
#include "operation-handler/OperationHandlerResult.h"
#include "util.h"

class MockTurnOffDigitalLightHandler : public TurnOffHandlerInterface {

public:

    MockTurnOffDigitalLightHandler(
        std::string name,
        std::string path,
        std::list<MockDigitalLightHw*> components
    ): TurnOffHandlerInterface(name, path, OperationType::ACTION) {
        _components = components;
    };

private:

    bool turnOff(std::string id) {
        std::optional<MockDigitalLightHw*> oc = find_by_id(_components, id);
        if(oc.has_value()) {
            oc.value() -> off();
            return true;
        } else {
            return false;
        }
    };
    
    std::list<MockDigitalLightHw*> _components;

};

#endif //BRITTANY_MOCK_TURN_OFF_DIGITAL_LIGHT_HANDLER_INTERFACE_H
