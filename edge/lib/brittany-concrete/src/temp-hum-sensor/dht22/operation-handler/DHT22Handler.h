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

#ifndef BRITTANY_DHT22_HANDLER_H
#define BRITTANY_DHT22_HANDLER_H

#include <string>
#include <list>
#include "operation-handler/interfaces/RetrieveValueFromComponentInterface.h"
#include "temp-hum-sensor/dht22/hw/DHT22SensorHw.h"

class DHT22Handler : public RetrieveValueFromComponentInterface<DHT22SensorHw, float> {

public:

    DHT22Handler(std::string name, std::list<DHT22SensorHw*> components)
        : RetrieveValueFromComponentInterface<DHT22SensorHw, float> (name, components) {

    };

private:

    virtual std::optional<float> sub_operation(DHT22SensorHw* hw, Json::Value args) = 0;

};

#endif //BRITTANY_DHT22_HANDLER_H
