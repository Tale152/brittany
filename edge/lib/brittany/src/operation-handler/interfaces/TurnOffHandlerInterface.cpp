#include "TurnOffHandlerInterface.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"

TurnOffHandlerInterface::TurnOffHandlerInterface(std::string name, std::string path, OperationType operationType) :
    ValueReturnedHandlerInterface<std::string>(name, path, operationType) {
    //does nothing
}

std::optional<std::string> TurnOffHandlerInterface::operation(Json::Value args) {
    if(args.isMember("id") && turnOff(args["id"].asCString())){
        return std::optional(phrase(ContentResult::Ok));
    }
    return std::nullopt;
}
