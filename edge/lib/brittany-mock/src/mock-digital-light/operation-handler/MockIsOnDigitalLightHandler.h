#ifndef BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
#define BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/RetrieveValueFromComponentInterface.h"
#include "mock-digital-light/hw/MockDigitalLightHw.h"
#include "operation-handler/OperationHandlerResult.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"
#include <optional>

class MockIsOnDigitalLightHandler
: public RetrieveValueFromComponentInterface<MockDigitalLightHw, bool> {

public:

    MockIsOnDigitalLightHandler(
        std::string name,
        std::string path,
        std::list<MockDigitalLightHw*> components
    ): RetrieveValueFromComponentInterface<MockDigitalLightHw, bool>(
        name,
        path,
        OperationType::PROPERTY,
        Type::BOOLEAN,
        components
    ) {

    };

private:

    std::optional<bool> sub_operation(MockDigitalLightHw* hw, Json::Value args) {
        return std::optional(hw -> isOn());
    }

};

#endif //BRITTANY_MOCK_IS_ON_DIGITAL_LIGHT_HANDLER_INTERFACE_H
