#ifndef BRITTANY_DHT22_HANDLER_H
#define BRITTANY_DHT22_HANDLER_H

#include <string>
#include <list>
#include "operation-handler/interfaces/RetrieveValueFromComponentInterface.h"
#include "temp-hum-sensor/dht22/hw/DHT22SensorHw.h"

class DHT22Handler : public RetrieveValueFromComponentInterface<DHT22SensorHw, float> {

public:

    DHT22Handler(std::string name, std::string path, std::list<DHT22SensorHw*> components)
    : RetrieveValueFromComponentInterface<DHT22SensorHw, float> (name, path, components) {

    };

private:

    virtual std::optional<float> sub_operation(DHT22SensorHw* hw, Json::Value args) = 0;

};

#endif //BRITTANY_DHT22_HANDLER_H
