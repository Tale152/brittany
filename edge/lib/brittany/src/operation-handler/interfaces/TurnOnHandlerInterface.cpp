#include "TurnOnHandlerInterface.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"

TurnOnHandlerInterface::TurnOnHandlerInterface(std::string path) : ValueReturnedHandlerInterface<std::string>(path) {
    //does nothing
}

std::optional<std::string> TurnOnHandlerInterface::operation(Json::Value args) {
    if(turnOn(args.asString())){
        return std::optional(phrase(ContentResult::Ok));
    }
    return std::nullopt;
}
