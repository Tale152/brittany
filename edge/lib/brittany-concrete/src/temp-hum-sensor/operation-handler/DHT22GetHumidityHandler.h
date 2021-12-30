#ifndef BRITTANY_DHT22_GET_HUMIDITY_HANDLER_H
#define BRITTANY_DHT22_GET_HUMIDITY_HANDLER_H

#include <string>
#include <list>
#include "operation-handler/interfaces/ValueReturnedHandlerInterface.h"
#include "temp-hum-sensor/hw/DHT22SensorHw.h"

class DHT22GetHumidityHandler : public ValueReturnedHandlerInterface<float> {

public:

    DHT22GetHumidityHandler(
        std::string name,
        std::string path,
        std::list<DHT22SensorHw*> components
    );

private:

    std::optional<float> operation(Json::Value args);

    std::list<DHT22SensorHw*> _components;
};

#endif //BRITTANY_DHT22_GET_HUMIDITY_HANDLER_H
