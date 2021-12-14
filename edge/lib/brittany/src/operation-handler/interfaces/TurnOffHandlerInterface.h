#ifndef BRITTANY_TURN_OFF_HANDLER_INTERFACE_H
#define BRITTANY_TURN_OFF_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/interfaces/OperationHandlerInterface.h"

/**
 * @brief Operation Handler Interface whose objective is to turn off a component.
 * 
 */
class TurnOffHandlerInterface : public OperationHandlerInterface {

public:

    TurnOffHandlerInterface(std::string path);

    bool operation(Json::Value args);

    /**
     * @brief turn off the chosen component.
     * 
     * @param id the id of the component to turn off.
     * @return true if the operation succeed.
     * @return false if the operation fails.
     */
    virtual bool turnOff(std::string id) = 0;

};

#endif //BRITTANY_TURN_OFF_HANDLER_INTERFACE_H
