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
