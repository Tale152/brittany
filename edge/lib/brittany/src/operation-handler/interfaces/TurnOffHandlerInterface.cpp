#include "TurnOffHandlerInterface.h"
#include "HttpStatusCodes_C++.h"

TurnOffHandlerInterface::TurnOffHandlerInterface(std::string path) : OperationHandler(path) {
    //does nothing
}

OperationHandlerResult TurnOffHandlerInterface::handle(Json::Value args) {
    if(turnOff(args.asString())) {
        return OperationHandlerResult(HttpStatus::OK, "Ok.");
    } else {
        return OperationHandlerResult(HttpStatus::NotFound, "Can't find this component.");
    }
}
