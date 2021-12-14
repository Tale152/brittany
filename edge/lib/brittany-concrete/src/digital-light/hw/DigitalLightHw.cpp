#include "DigitalLightHw.h"
#include <Arduino.h>

DigitalLightHw::DigitalLightHw(std::string id, uint8_t pin) : DigitalLightHwInterface(id, pin) {
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

