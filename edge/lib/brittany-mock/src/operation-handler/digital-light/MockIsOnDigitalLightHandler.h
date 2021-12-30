#ifndef BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
#define BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/ValueReturnedHandlerInterface.h"
#include "../../hw/MockDigitalLightHw.h"
#include "operation-handler/OperationHandlerResult.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"
#include <optional>

class MockIsOnDigitalLightHandler : public ValueReturnedHandlerInterface<bool> {

public:

    MockIsOnDigitalLightHandler(
        std::string name,
        std::string path,
        std::list<MockDigitalLightHw*> components
    ): ValueReturnedHandlerInterface<bool>(name, path, OperationType::PROPERTY) {
        _components = components;
    };

private:

    std::optional<bool> operation(Json::Value args) {
        if(args.isMember("id")) {
            MockDigitalLightHw* component = find_by_id(_components, args["id"].asCString());
            if(component != NULL){
                return std::optional(component -> isOn());
            }
        }
        return std::nullopt;
    };
    
    std::list<MockDigitalLightHw*> _components;

};

#endif //BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
