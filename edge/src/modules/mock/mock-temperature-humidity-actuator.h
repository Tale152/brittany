#ifdef BRITTANY_MAIN_MOCK_TEMPERATURE_HUMIDITY_ACTUATOR

#include "edge/Edge.h"
#include "mock-switchable/hw/MockSwitchableHw.h"
#include "mock-temperature-actuator/modules/MockTemperatureCoolerModule.h"
#include "mock-temperature-actuator/modules/MockTemperatureHeaterModule.h"
#include "mock-humidity-actuator/modules/MockHumidifierModule.h"
#include "mock-humidity-actuator/modules/MockDehumidifierModule.h"

Edge* edge() {
    MockSwitchableHw* heater = new MockSwitchableHw("heater");
    MockSwitchableHw* cooler = new MockSwitchableHw("cooler");
    MockSwitchableHw* humidifier = new MockSwitchableHw("humidifier");
    MockSwitchableHw* dehumidifier = new MockSwitchableHw("dehumidifier");
    std::list<Module*> modules;
    modules.push_back(new MockTemperatureHeaterModule({heater}));
    modules.push_back(new MockTemperatureCoolerModule({cooler}));
    modules.push_back(new MockHumidifierModule({humidifier}));
    modules.push_back(new MockDehumidifierModule({dehumidifier}));
    std::string edge_desc = "Mock Temperature Edge that can increase and lower the temperature and the humidity.";
    return new Edge(edge_desc, modules);
}

#endif