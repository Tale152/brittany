#include "DHT22GetTemperatureHandler.h"
#include "util.h"

DHT22GetTemperatureHandler::DHT22GetTemperatureHandler(
    std::string name,
    std::list<DHT22SensorHw*> components
): DHT22Handler(name, components) {

}

std::optional<float> DHT22GetTemperatureHandler::sub_operation(DHT22SensorHw* hw, Json::Value args) {
    if(args.isMember("unit")) {
        if(args["unit"] == "C" || args["unit"] == "c") {
            return hw -> temperatureCelsius();
        } else if(args["unit"] == "K" || args["unit"] == "k") {
            return hw -> temperatureKelvin();
        } else if(args["unit"] == "F" || args["unit"] == "f") {
            return hw -> temperatureFahrenheit();
        }
        return std::nullopt;
    }
    return hw -> temperatureCelsius();
}
