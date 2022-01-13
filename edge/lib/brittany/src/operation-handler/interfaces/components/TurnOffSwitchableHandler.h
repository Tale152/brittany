#ifndef BRITTANY_TURN_OFF_SWITCHABLE_HANDLER_H
#define BRITTANY_TURN_OFF_SWITCHABLE_HANDLER_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/RetrieveValueFromComponentInterface.h"
#include "util.h"

template <class C>

class TurnOffSwitchableHandler
: public RetrieveValueFromComponentInterface<C, std::string> {

public:

    TurnOffSwitchableHandler(
        std::string name,
        std::string path,
        std::list<C*> components
    ): RetrieveValueFromComponentInterface<C, std::string>(
        name,
        path,
        OperationType::ACTION,
        Type::STRING,
        components
    ) {

    }

private:

    std::optional<std::string> sub_operation(C* hw, Json::Value args) {
        hw -> off();
        return std::optional(phrase(ContentResult::Ok));
    };

};

#endif //BRITTANY_TURN_OFF_SWITCHABLE_HANDLER_H
