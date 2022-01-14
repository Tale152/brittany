#ifdef BRITTANY_MAIN_MOCK_TEMPERATURE_HUMIDITY_ACTUATOR

#include "edge/Edge.h"
#include "mock-switchable/hw/MockSwitchableHw.h"
#include "mock-temperature-actuator/modules/MockTemperatureCoolerModule.h"
#include "mock-temperature-actuator/modules/MockTemperatureHeaterModule.h"
#include "mock-humidity-actuator/modules/MockHumidifierModule.h"

Edge* edge() {
    MockSwitchableHw* heater = new MockSwitchableHw("heater");
    MockSwitchableHw* cooler = new MockSwitchableHw("cooler");
    MockSwitchableHw* humidifier = new MockSwitchableHw("humidifier");
    std::list<Module*> modules;
    modules.push_back(new MockTemperatureHeaterModule({heater}));
    modules.push_back(new MockTemperatureCoolerModule({cooler}));
    modules.push_back(new MockHumidifierModule({humidifier}));
    return new Edge("Mock Temperature Edge that can increase and lower the temperature.", modules);
}

#endif