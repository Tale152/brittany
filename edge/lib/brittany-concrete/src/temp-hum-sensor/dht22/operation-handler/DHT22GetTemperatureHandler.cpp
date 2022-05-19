//
// Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "DHT22GetTemperatureHandler.h"
#include "util.h"

DHT22GetTemperatureHandler::DHT22GetTemperatureHandler(
    std::string name,
    std::list<DHT22SensorHw*> components
): DHT22Handler(name, components) {

}

std::optional<float> DHT22GetTemperatureHandler::sub_operation(DHT22SensorHw* hw, Json::Value args) {
    if(args.isMember("unit")) {
        if(args["unit"] == "C" || args["unit"] == "c") {
            return hw -> temperatureCelsius();
        } else if(args["unit"] == "K" || args["unit"] == "k") {
            return hw -> temperatureKelvin();
        } else if(args["unit"] == "F" || args["unit"] == "f") {
            return hw -> temperatureFahrenheit();
        }
        return std::nullopt;
    }
    return hw -> temperatureCelsius();
}
