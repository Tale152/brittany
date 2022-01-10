#include "TurnOffHandlerInterface.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"

TurnOffHandlerInterface::TurnOffHandlerInterface(std::string name, std::string path)
: ValueReturnedAfterActionHandlerInterface<std::string>(name, path, OperationType::ACTION, Type::STRING) {
    //does nothing
}

 std::optional<std::string> TurnOffHandlerInterface::retrieveValue(Json::Value args) {
    if(turnOff(args["id"].asCString())){
        return std::optional(phrase(ContentResult::Ok));
    }
    return std::nullopt;
}