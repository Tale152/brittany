#include "modules/ComponentModule.h"
#include "temp-hum-sensor/hw/DHT22SensorHw.h"
#include "temp-hum-sensor/operation-handler/DHT22GetTemperatureHandler.h"
#include "util.h"

#define DHT22_GET_TEMPERATURE_HANDLER_NAME "temperature"

class MockDigitalLightModule : public ComponentModule<DHT22SensorHw> {

public:

    MockDigitalLightModule(std::string name, std::list<DHT22SensorHw*> components): ComponentModule<DHT22SensorHw>(name, components) {
        _handlers.push_back(
            new DHT22GetTemperatureHandler(
                DHT22_GET_TEMPERATURE_HANDLER_NAME,
                as_route(DHT22_GET_TEMPERATURE_HANDLER_NAME),
                components
            )
        );
    };

};
