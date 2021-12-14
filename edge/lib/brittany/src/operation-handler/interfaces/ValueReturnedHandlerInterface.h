#ifndef BRITTANY_VALUE_RETURNED_HANDLER_INTERFACE_H
#define BRITTANY_VALUE_RETURNED_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/OperationHandler.h"
#include <optional>

template <typename T>

class ValueReturnedHandlerInterface : public OperationHandler {

public:

    ValueReturnedHandlerInterface(std::string path);

    OperationHandlerResult handle(Json::Value args);

private:
    
    virtual std::optional<T> operation(Json::Value args) = 0;

};

#endif //BRITTANY_TURN_ON_HANDLER_INTERFACE_H
