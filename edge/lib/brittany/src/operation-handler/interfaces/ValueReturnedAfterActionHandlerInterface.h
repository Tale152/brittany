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

class ValueReturnedAfterActionHandlerInterface : public ValueReturnedHandlerInterface<T> {

public:

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

    virtual std::optional<T> retrieveValue(Json::Value args) = 0;

};

#endif //BRITTANY_VALUE_RETURNED_AFTER_ACTION_HANDLER_INTERFACE_H
