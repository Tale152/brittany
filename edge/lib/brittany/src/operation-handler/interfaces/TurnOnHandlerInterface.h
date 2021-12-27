#ifndef BRITTANY_TURN_ON_HANDLER_INTERFACE_H
#define BRITTANY_TURN_ON_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <optional>
#include <json/json.h>
#include "operation-handler/interfaces/ValueReturnedHandlerInterface.h"

/**
 * @brief Operation Handler Interface whose objective is to turn on a component.
 * 
 */
class TurnOnHandlerInterface : public ValueReturnedHandlerInterface<std::string> {

public:

    TurnOnHandlerInterface(std::string name, std::string path);

    /**
     * @brief template method that call the turnOn method.
     * 
     * @param args The arguments that the operation uses.
     * @return std::optional<std::string> an empty optional if operation fails, an "Ok." otherwise.
     */
    std::optional<std::string> operation(Json::Value args);

    /**
     * @brief turn on the chosen component.
     * 
     * @param id the id of the component to turn on.
     * @return true if the operation succeed.
     * @return false if the operation fails.
     */
    virtual bool turnOn(std::string id) = 0;

};

#endif //BRITTANY_TURN_ON_HANDLER_INTERFACE_H
