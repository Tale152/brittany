#ifndef BRITTANY_TURN_OFF_HANDLER_INTERFACE_H
#define BRITTANY_TURN_OFF_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <optional>
#include <json/json.h>
#include "operation-handler/interfaces/ValueReturnedAfterActionHandlerInterface.h"

/**
 * @brief Operation Handler Interface whose objective is to turn off a component.
 */
class TurnOffHandlerInterface : public ValueReturnedAfterActionHandlerInterface<std::string> {

public:

    TurnOffHandlerInterface(std::string name, std::string path);

    std::optional<std::string> retrieveValue(Json::Value args);

    virtual bool turnOff(std::string id) = 0;

};

#endif //BRITTANY_TURN_OFF_HANDLER_INTERFACE_H
