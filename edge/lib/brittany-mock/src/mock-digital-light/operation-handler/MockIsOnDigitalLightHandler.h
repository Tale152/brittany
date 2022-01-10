#ifndef BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
#define BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/ValueReturnedAfterActionHandlerInterface.h"
#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "operation-handler/OperationHandlerResult.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"
#include <optional>

class MockIsOnDigitalLightHandler : public ValueReturnedAfterActionHandlerInterface<bool> {

public:

    MockIsOnDigitalLightHandler(
        std::string name,
        std::string path,
        std::list<MockDigitalLightHw*> components
    ): ValueReturnedAfterActionHandlerInterface<bool>(
        name,
        path,
        OperationType::PROPERTY,
        Type::BOOLEAN
    ) {
        _components = components;
    };

private:

    std::optional<bool> retrieveValue(Json::Value args) {
        std::optional<MockDigitalLightHw*> oc = find_by_id(_components, args["id"].asCString());
        if(oc.has_value()){
            return std::optional(oc.value() -> isOn());
        }
        return std::nullopt;
    }
    
    std::list<MockDigitalLightHw*> _components;

};

#endif //BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
