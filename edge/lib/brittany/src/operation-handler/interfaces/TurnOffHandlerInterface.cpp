#include "TurnOffHandlerInterface.h"
#include "HttpStatusCodes_C++.h"

TurnOffHandlerInterface::TurnOffHandlerInterface(std::string path) : OperationHandlerInterface(path) {
    //does nothing
}

bool TurnOffHandlerInterface::operation(Json::Value args) {
    return turnOff(args.asString());
}
