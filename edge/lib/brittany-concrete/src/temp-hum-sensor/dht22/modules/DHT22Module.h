#ifndef BRITTANY_DHT22_MODULE
#define BRITTANY_DHT22_MODULE

#include "modules/ComponentModule.h"
#include "temp-hum-sensor/dht22/hw/DHT22SensorHw.h"
#include "temp-hum-sensor/dht22/operation-handler/DHT22GetTemperatureHandler.h"
#include "temp-hum-sensor/dht22/operation-handler/DHT22GetHumidityHandler.h"
#include "util.h"

#define DHT22_GET_TEMPERATURE_HANDLER_NAME "temperature"
#define DHT22_GET_HUMIDITY_HANDLER_NAME "humidity"

class DHT22Module : public ComponentModule<DHT22SensorHw> {

public:

    DHT22Module(std::string name, std::list<DHT22SensorHw*> components): ComponentModule<DHT22SensorHw>(name, components) {
        _handlers.push_back(
            new DHT22GetTemperatureHandler(DHT22_GET_TEMPERATURE_HANDLER_NAME, components)
        );
         _handlers.push_back(
            new DHT22GetHumidityHandler(DHT22_GET_HUMIDITY_HANDLER_NAME, components)
        );
    };

};

#endif //BRITTANY_DHT22_MODULE
