#include "TurnOnHandlerInterface.h"
#include "HttpStatusCodes_C++.h"

TurnOnHandlerInterface::TurnOnHandlerInterface(std::string path) : OperationHandlerInterface(path) {
    //does nothing
}

bool TurnOnHandlerInterface::operation(Json::Value args) {
    return turnOn(args.asString());
}
