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

#ifdef BRITTANY_MAIN_DHT22

#include "temp-hum-sensor/dht22/hw/DHT22SensorHw.h"
#include "temp-hum-sensor/dht22/modules/DHT22Module.h"

Edge* edge() {
    DHT22SensorHw* dht22 = new DHT22SensorHw("dht22", D5);
    std::list<DHT22SensorHw*> sensors = std::list<DHT22SensorHw*>({dht22});
    std::list<Module*> modules;
    modules.push_back(new DHT22Module("temp-hum", sensors));
    return new Edge("Temperature and Humidity Edge", modules);
}

#endif