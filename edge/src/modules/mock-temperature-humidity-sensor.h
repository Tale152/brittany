#ifdef BRITTANY_MAIN_MOCK_TEMPERATURE_HUMIDITY_SENSOR

#include "mock-humidity-sensor/hw/MockHumiditySensorHw.h"
#include "mock-humidity-sensor/modules/MockHumidityModule.h"

Edge* edge() {
    MockHumiditySensorHw* humSensor = new MockHumiditySensorHw("hum");
    std::list<MockHumiditySensorHw*> sensors = std::list<MockHumiditySensorHw*>({humSensor});
    std::list<Module*> modules;
    modules.push_back(new MockHumidityModule(sensors));
    return new Edge("Mock Humidity and Temperature Edge", modules);
}

#endif