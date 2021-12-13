#include "OnePin.h"

OnePin::OnePin(uint8_t pin) {
    _pin = pin;
}

uint8_t OnePin::pin() {
    return _pin;
}
