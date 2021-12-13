#include "MockDigitalLightHw.h"

void MockDigitalLightHw::on() {
    _isOn = true;
}

void MockDigitalLightHw::off() {
    _isOn = false;
}

bool MockDigitalLightHw::isOn() {
    return _isOn;
}
