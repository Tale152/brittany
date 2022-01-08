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


    /**
     * @brief Calls the turnOff method.
     * 
     * @param args the arguments passed from operation.
     * @return std::optional<std::string> a string  with an "Ok." message if everything worked.
     * Empty otherise.
     */
    std::optional<std::string> retrieveValue(Json::Value args);

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
