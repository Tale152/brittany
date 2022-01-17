#ifdef BRITTANY_MAIN_MOCK_TEMPERATURE_HUMIDITY

#include "mock-switchable/hw/MockSwitchableHw.h"
#include "mock-temperature-actuator/modules/MockTemperatureCoolerModule.h"
#include "mock-temperature-actuator/modules/MockTemperatureHeaterModule.h"
#include "mock-humidity-actuator/modules/MockHumidifierModule.h"
#include "mock-humidity-actuator/modules/MockDehumidifierModule.h"
#include "mock-temperature-sensor/hw/MockTemperatureSensorHw.h"
#include "mock-temperature-sensor/modules/MockTemperatureModule.h"
#include "mock-humidity-sensor/hw/MockHumiditySensorHw.h"
#include "mock-humidity-sensor/modules/MockHumidityModule.h"

Edge* edge() {
    MockSwitchableHw* heater = new MockSwitchableHw("heater");
    MockSwitchableHw* cooler = new MockSwitchableHw("cooler");
    MockSwitchableHw* humidifier = new MockSwitchableHw("humidifier");
    MockSwitchableHw* dehumidifier = new MockSwitchableHw("dehumidifier");
    MockHumiditySensorHw* humSensor = new MockHumiditySensorHw("hum");
    MockTemperatureSensorHw* tempSensor = new MockTemperatureSensorHw("temp");
    std::list<Module*> modules;
    modules.push_back(new MockTemperatureHeaterModule({heater}));
    modules.push_back(new MockTemperatureCoolerModule({cooler}));
    modules.push_back(new MockHumidifierModule({humidifier}));
    modules.push_back(new MockDehumidifierModule({dehumidifier}));
    modules.push_back(new MockHumidityModule({humSensor}));
    modules.push_back(new MockTemperatureModule({tempSensor}));
    std::string edge_desc = "Mock Temperature Edge for handling temperature and humidity.";
    return new Edge(edge_desc, modules);
}

#endif