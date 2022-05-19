/* * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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