#ifndef BRITTANY_DHT22_GET_TEMPERATURE_HANDLER_H
#define BRITTANY_DHT22_GET_TEMPERATURE_HANDLER_H

#include <string>
#include <list>
#include "operation-handler/interfaces/ValueReturnedHandlerInterface.h"
#include "temp-hum-sensor/hw/DHT22SensorHw.h"

class DHT22GetTemperatureHandler : public ValueReturnedHandlerInterface<float> {

public:

    DHT22GetTemperatureHandler(
        std::string name,
        std::string path,
        std::list<DHT22SensorHw*> components
    );

    std::optional<float> operation(Json::Value args);

private:

    std::list<DHT22SensorHw*> _components;
};

#endif //BRITTANY_DHT22_GET_TEMPERATURE_HANDLER_H
