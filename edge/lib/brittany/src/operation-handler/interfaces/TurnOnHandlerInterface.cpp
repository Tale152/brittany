#include "TurnOnHandlerInterface.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"

TurnOnHandlerInterface::TurnOnHandlerInterface(std::string name, std::string path)
: ValueReturnedAfterActionHandlerInterface<std::string>(name, path, OperationType::ACTION, Type::STRING) {
    //does nothing
}

std::optional<std::string> TurnOnHandlerInterface::retrieveValue(Json::Value args) {
    if(turnOn(args["id"].asCString())) {
        return std::optional(phrase(ContentResult::Ok));
    }
    return std::nullopt;
}
