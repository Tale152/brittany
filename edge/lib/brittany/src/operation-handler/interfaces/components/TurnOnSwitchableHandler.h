#ifndef BRITTANY_TURN_ON_SWITCHABLE_HANDLER_H
#define BRITTANY_TURN_ON_SWITCHABLE_HANDLER_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/RetrieveValueFromComponentInterface.h"
#include "util.h"

template <class C>

class TurnOnSwitchableHandler
: public RetrieveValueFromComponentInterface<C, std::string> {

public:

    TurnOnSwitchableHandler(
        std::string name,
        std::list<C*> components
    ): RetrieveValueFromComponentInterface<C, std::string>(
        name,
        OperationType::ACTION,
        Type::STRING,
        components
    ) {

    }

private:

    std::optional<std::string> sub_operation(C* hw, Json::Value args) {
        hw -> on();
        return std::optional(phrase(ContentResult::Ok));
    };

};

#endif //BRITTANY_TURN_ON_SWITCHABLE_HANDLER_H
