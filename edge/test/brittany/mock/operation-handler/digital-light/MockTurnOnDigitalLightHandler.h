#ifndef BRITTANY_TURN_ON_HANDLER_INTERFACE_H
#define BRITTANY_TURN_ON_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/TurnOnHandlerInterface.h"
#include "mock/hw/MockDigitalLightHw.h"
#include "operation-handler/OperationHandlerResult.h"

class MockTurnOnDigitalLightHandler : public TurnOnHandlerInterface {

public:

    MockTurnOnDigitalLightHandler(std::string path, std::list<MockDigitalLightHw*> components){
        _components = components;
    };

    virtual bool turnOn(std::string id);

private:

    std::list<MockDigitalLightHw*> _components;

};

#endif //BRITTANY_TURN_ON_HANDLER_INTERFACE_H
