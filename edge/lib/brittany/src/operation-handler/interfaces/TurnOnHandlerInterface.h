#ifndef BRITTANY_TURN_ON_HANDLER_INTERFACE_H
#define BRITTANY_TURN_ON_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/OperationHandlerInterface.h"

/**
 * @brief Operation Handler Interface whose objective is to turn on a component.
 * 
 */
class TurnOnHandlerInterface : public OperationHandlerInterface {

public:

    TurnOnHandlerInterface(std::string path);

    OperationHandlerResult handle(Json::Value args);

    bool operation(Json::Value args);

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
