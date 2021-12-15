#include "TurnOffHandlerInterface.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"

TurnOffHandlerInterface::TurnOffHandlerInterface(std::string path) : ValueReturnedHandlerInterface<std::string>(path) {
    //does nothing
}

std::optional<std::string> TurnOffHandlerInterface::operation(Json::Value args) {
    if(turnOff(args.asString())){
        return std::optional(phrase(ContentResult::Ok));
    }
    return std::nullopt;
}
