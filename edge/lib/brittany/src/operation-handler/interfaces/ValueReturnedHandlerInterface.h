#ifndef BRITTANY_VALUE_RETURNED_HANDLER_INTERFACE_H
#define BRITTANY_VALUE_RETURNED_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/OperationHandler.h"
#include <optional>
#include "ValueReturnedHandlerInterface.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"
#include "operation-handler/interfaces/util/ValueReturnedResult.h"

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
     */
    ValueReturnedHandlerInterface(
        std::string name,
        OperationType operationType,
        Type outputType
        ) : OperationHandler(
            name,
            operationType,
            outputType
        ) {
        //does nothing
    };

    OperationHandlerResult handle(Json::Value args) {
        ValueReturnedResult<T> result = operation(args);
        if(result.value().has_value()) {
            // Return the value
            return OperationHandlerResult(result.code(), Json::Value(result.value().value()));
        } else {
            // Return the description message if present 
            if(result.message().has_value()) {
                return OperationHandlerResult(result.code(), Json::Value(result.message().value()));
            }
        }
        // Return a very generic error message
        return OperationHandlerResult(result.code(), Json::Value(phrase(ContentResult::OperationFailed)));
    };

private:
    
    /**
     * @brief execute an operation that may return a value that is then processed by the handle method.
     * 
     * @param args the arguments used by the operation.
     * @return ValueReturnedResult the result struct of the operation.
     */
    virtual ValueReturnedResult<T> operation(Json::Value args) = 0;

};

#endif //BRITTANY_TURN_ON_HANDLER_INTERFACE_H
