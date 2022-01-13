//#ifdef BRITTANY_MAIN_MOCK_TEMPERATURE_HUMIDITY_SENSOR

#include "mock-temperature-sensor/hw/MockTemperatureSensorHw.h"
#include "mock-temperature-sensor/modules/MockTemperatureModule.h"
#include "mock-humidity-sensor/hw/MockHumiditySensorHw.h"
#include "mock-humidity-sensor/modules/MockHumidityModule.h"

Edge* edge() {
    MockHumiditySensorHw* humSensor = new MockHumiditySensorHw("hum");
    MockTemperatureSensorHw* tempSensor = new MockTemperatureSensorHw("temp");
    std::list<Module*> modules;
    modules.push_back(new MockHumidityModule({humSensor}));
    modules.push_back(new MockTemperatureModule({tempSensor}));
    return new Edge("Mock Humidity and Temperature Edge", modules);
}

//#endif