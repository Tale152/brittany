#include "TurnOnHandlerInterface.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"

TurnOnHandlerInterface::TurnOnHandlerInterface(std::string name, std::string path, OperationType operationType) :
    ValueReturnedHandlerInterface<std::string>(name, path, operationType) {
    //does nothing
}

std::optional<std::string> TurnOnHandlerInterface::operation(Json::Value args) {
    if(args.isMember("id") && turnOn(args["id"].asCString())){
        return std::optional(phrase(ContentResult::Ok));
    }
    return std::nullopt;
}
