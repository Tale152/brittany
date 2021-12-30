#ifndef BRITTANY_DHT22_GET_HUMIDITY_HANDLER_H
#define BRITTANY_DHT22_GET_HUMIDITY_HANDLER_H

#include <string>
#include <list>
#include "DHT22Handler.h"
#include "temp-hum-sensor/hw/DHT22SensorHw.h"

class DHT22GetHumidityHandler : public DHT22Handler {

public:

    DHT22GetHumidityHandler(
        std::string name,
        std::string path,
        std::list<DHT22SensorHw*> components
    );

private:

    std::optional<float> sub_operation(DHT22SensorHw* hw, Json::Value args);

    std::list<DHT22SensorHw*> _components;
};

#endif //BRITTANY_DHT22_GET_HUMIDITY_HANDLER_H
