#ifndef BRITTANY_VALUE_RETURNED_AFTER_ACTION_HANDLER_INTERFACE_H
#define BRITTANY_VALUE_RETURNED_AFTER_ACTION_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/OperationHandler.h"
#include <optional>
#include "ValueReturnedHandlerInterface.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"
#include "operation-handler/interfaces/util/ValueReturnedResult.h"

template <typename T>

/**
 * @brief Handler Interface that uses the id in the arguments to execute and action and return a value.
 * 
 */
class ValueReturnedAfterActionHandlerInterface : public ValueReturnedHandlerInterface<T> {

public:

    /**
     * @brief Construct a new Value Returned After Action Handler Interface object.
     * 
     * @param name the name of the handler.
     * @param path the path of the handler.
     * @param operationType the operationType of the handler.
     * @param outputType the output type of the handler.
     */
    ValueReturnedAfterActionHandlerInterface(
        std::string name,
        std::string path,
        OperationType operationType,
        Type outputType
    ) : ValueReturnedHandlerInterface<T>(
        name,
        path,
        operationType,
        outputType
    ) {};

private:
    
    /**
     * @brief Check if id is present amoung the arguments, call retrieveValue if id is present.
     * 
     * @param args the arguments passed by handle.
     * @return ValueReturnedResult<T> return the ValueReturnedResult with:
     * OK as code and the value if everything works fine.
     * NotFound and a not found message if the id can't be found.
     * BadRequest and a bad request message id id is not in the arguments.
     */
    ValueReturnedResult<T> operation(Json::Value args) {
        if(args.isMember("id")){
            std::optional<T> value = retrieveValue(args);
            if(value.has_value()){
                return ValueReturnedResult<T>(
                    HttpStatus::OK,
                    value.value()
                );
            } else {
                return ValueReturnedResult<T>(
                    HttpStatus::NotFound,
                    std::nullopt,
                    phrase(ContentResult::ResourceNotFound)
                );
            }
        }
        return ValueReturnedResult<T>(
            HttpStatus::BadRequest,
            std::nullopt,
            phrase(ContentResult::BadRequest)
        );
    };

    /**
     * @brief Abstract method that may return the value.
     * 
     * @param args the arguments passed by operation.
     * @return std::optional<T> the value if everything works fine, false otherwise.
     */
    virtual std::optional<T> retrieveValue(Json::Value args) = 0;

};

#endif //BRITTANY_VALUE_RETURNED_AFTER_ACTION_HANDLER_INTERFACE_H
