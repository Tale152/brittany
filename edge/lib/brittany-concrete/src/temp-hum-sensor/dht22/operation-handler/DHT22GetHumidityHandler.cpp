#include "DHT22GetHumidityHandler.h"
#include "util.h"

DHT22GetHumidityHandler::DHT22GetHumidityHandler(
    std::string name,
    std::list<DHT22SensorHw*> components
): DHT22Handler(name, components) {

}

std::optional<float> DHT22GetHumidityHandler::sub_operation(DHT22SensorHw* hw, Json::Value args) {
    return hw -> humidity();
}
