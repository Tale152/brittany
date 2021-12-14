#include "OperationHandlerInterface.h"
#include "HttpStatusCodes_C++.h"

OperationHandlerInterface::OperationHandlerInterface(std::string path) : OperationHandler(path) {
    //does nothing
}

OperationHandlerResult OperationHandlerInterface::handle(Json::Value args) {
    if(operation(args)) {
        return OperationHandlerResult(HttpStatus::OK, "Ok.");
    } else {
        return OperationHandlerResult(HttpStatus::NotFound, "Operation failed.");
    }
}
