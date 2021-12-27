#ifndef BRITTANY_VALUE_RETURNED_HANDLER_INTERFACE_H
#define BRITTANY_VALUE_RETURNED_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/OperationHandler.h"
#include <optional>

/**
 * @brief Type of the parameter to be returned by this class.
 * 
 * @tparam T the type of return of the operation.
 */
template <typename T>

/**
 * @brief A handler that may return a generic value, wrapped in a std::optional in case of failures.
 */
class ValueReturnedHandlerInterface : public OperationHandler {

public:

    /**
     * @brief Construct a new Value Returned Handler Interface object
     * 
     * @param name the name of the handler.
     * @param path the path(route) of the handler.
     */
    ValueReturnedHandlerInterface(std::string name, std::string path, OperationType operationType);

    OperationHandlerResult handle(Json::Value args);

private:
    
    /**
     * @brief execute an operation that may return a value that is then processed by the handle method.
     * 
     * @param args the arguments used by the operation.
     * @return std::optional<T> a generic return type wrapped in an optional in case of failures.
     */
    virtual std::optional<T> operation(Json::Value args) = 0;

};

#endif //BRITTANY_TURN_ON_HANDLER_INTERFACE_H
