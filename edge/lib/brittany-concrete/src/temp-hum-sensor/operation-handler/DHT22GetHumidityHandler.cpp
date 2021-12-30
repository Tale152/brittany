#include "DHT22GetHumidityHandler.h"
#include "util.h"
#include "thing-descriptor/OperationType.h"

DHT22GetHumidityHandler::DHT22GetHumidityHandler(std::string name, std::string path, std::list<DHT22SensorHw*> components)
: ValueReturnedHandlerInterface<float>(name, path, OperationType::PROPERTY) {
    _components = components;
}

std::optional<float> DHT22GetHumidityHandler::operation(Json::Value args) {
    if(args.isMember("id")) {
        std::optional<DHT22SensorHw*> oc = find_by_id(_components, args["id"].asCString());
        if(oc.has_value()) {
            return oc.value() -> humidity();
        }
        return std::nullopt; // failed to retrieve component
    }
    return std::nullopt; // id not found
}
