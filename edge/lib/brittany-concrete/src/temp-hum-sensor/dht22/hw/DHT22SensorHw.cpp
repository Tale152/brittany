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

#include "DHT22SensorHw.h"

DHT22SensorHw::DHT22SensorHw(std::string id, uint8_t pin) : TempHumHwInterface(id, pin), dht(pin, DHT22) {
    dht.begin();
}

std::optional<float> DHT22SensorHw::temperatureCelsius() {
    float temp = dht.readTemperature();
    return isnan(temp) ? std::nullopt : std::optional(temp);
}

std::optional<float> DHT22SensorHw::temperatureKelvin() {
    std::optional<float> tempC = temperatureCelsius();
    if(tempC.has_value()){
        return std::optional(Temperature::fromCToK(tempC.value()));
    }
    return std::nullopt;
}

std::optional<float> DHT22SensorHw::temperatureFahrenheit() {
    float temp = dht.readTemperature(true);
    return isnan(temp) ? std::nullopt : std::optional(temp);
}

std::optional<float> DHT22SensorHw::humidity() {
    float humidity = dht.readHumidity();
    return isnan(humidity) ? std::nullopt : std::optional(humidity);
}