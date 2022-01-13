#ifndef BRITTANY_IS_ON_SWITCHABLE_HANDLER_H
#define BRITTANY_IS_ON_SWITCHABLE_HANDLER_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/RetrieveValueFromComponentInterface.h"
#include "util.h"

template <class C>

class IsOnSwitchableHandler: public RetrieveValueFromComponentInterface<C, bool> {

public:

    IsOnSwitchableHandler(
        std::string name,
        std::string path,
        std::list<C*> components
    ): RetrieveValueFromComponentInterface<C, bool>(
        name,
        path,
        OperationType::PROPERTY,
        Type::BOOLEAN,
        components
    ) {

    }

private:

    std::optional<bool> sub_operation(C* hw, Json::Value args) {
        return std::optional(hw -> isOn());
    }

};

#endif //BRITTANY_IS_ON_SWITCHABLE_HANDLER_H
