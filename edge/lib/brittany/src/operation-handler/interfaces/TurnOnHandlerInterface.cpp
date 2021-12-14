#include "TurnOnHandlerInterface.h"
#include "HttpStatusCodes_C++.h"

TurnOnHandlerInterface::TurnOnHandlerInterface(std::string path) : OperationHandler(path) {
    //does nothing
}

OperationHandlerResult TurnOnHandlerInterface::handle(Json::Value args) {
    if(turnOn(args.asString())) {
        return OperationHandlerResult(HttpStatus::OK, "Ok.");
    } else {
        return OperationHandlerResult(HttpStatus::NotFound, "Can't find this component.");
    }
}



