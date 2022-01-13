#ifndef BRITTANY_TURN_OFF_HANDLER_INTERFACE_H
#define BRITTANY_TURN_OFF_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <optional>
#include <json/json.h>
#include "operation-handler/interfaces/RetrieveValueFromComponentInterface.h"

template <class C>
/**
 * @brief Operation Handler Interface whose objective is to turn off a component.
 */
class TurnOffHandlerInterface : public RetrieveValueFromComponentInterface<C, std::string> {

public:

    TurnOffHandlerInterface(std::string name, std::string path, std::list<C*> components)
    : RetrieveValueFromComponentInterface<C, std::string>(
        name,
        path,
        OperationType::ACTION,
        Type::STRING,
        components
    ) {
        //does nothing
    }

};

#endif //BRITTANY_TURN_OFF_HANDLER_INTERFACE_H
