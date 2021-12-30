#include "DHT22GetTemperatureHandler.h"
#include "util.h"
#include "thing-descriptor/OperationType.h"

DHT22GetTemperatureHandler::DHT22GetTemperatureHandler(std::string name, std::string path, std::list<DHT22SensorHw*> components)
: ValueReturnedHandlerInterface<float>(name, path, OperationType::PROPERTY) {
    _components = components;
}

std::optional<float> DHT22GetTemperatureHandler::operation(Json::Value args) {
    if(args.isMember("id")) {
        std::optional<DHT22SensorHw*> oc = find_by_id(_components, args["id"].asCString());
        if(oc.has_value()) {
            DHT22SensorHw* c = oc.value();
            if(args.isMember("unit")){
                if(args["unit"] == "C" || args["unit"] == "c") {
                    return c -> temperatureCelsius();
                } else if(args["unit"] == "K" || args["unit"] == "k") {
                    return c -> temperatureKelvin();
                } else if(args["unit"] == "F" || args["unit"] == "f") {
                    return c -> temperatureFahrenheit();
                } else {
                    return std::nullopt;
                }
            }
            return c -> temperatureCelsius();
        }
        return std::nullopt; // failed to retrieve component
    }
    return std::nullopt; // id not found
}
