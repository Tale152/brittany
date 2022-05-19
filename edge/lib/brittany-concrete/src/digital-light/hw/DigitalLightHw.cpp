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

#include "DigitalLightHw.h"
#include <Arduino.h>

DigitalLightHw::DigitalLightHw(std::string id, uint8_t pin) : DigitalLightHwInterface(id), OnePin(pin) {
    pinMode(pin, OUTPUT);
}

void DigitalLightHw::on() {
    digitalWrite(pin(), HIGH);
}

void DigitalLightHw::off() {
    digitalWrite(pin(), LOW);
}

bool DigitalLightHw::isOn() {
    return digitalRead(pin()) == HIGH;
}

