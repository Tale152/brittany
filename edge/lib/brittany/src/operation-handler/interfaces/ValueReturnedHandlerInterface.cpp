#include "ValueReturnedHandlerInterface.h"
#include "HttpStatusCodes_C++.h"
#include <optional>
#include "util.h"

template <typename T>
ValueReturnedHandlerInterface<T>::ValueReturnedHandlerInterface(std::string path) : OperationHandler(path) {
    //does nothing
}

template <typename T>
OperationHandlerResult ValueReturnedHandlerInterface<T>::handle(Json::Value args) {
    std::optional<T> result = operation(args);
    if(result.has_value()){
        return OperationHandlerResult(HttpStatus::OK, Json::Value(result.value()));
    } else {
        return OperationHandlerResult(HttpStatus::NotFound, Json::Value(phrase(ContentResult::OperationFailed)));
    }
    
}
