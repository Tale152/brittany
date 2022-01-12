#ifndef BRITTANY_TEMPERATURE_SENSOR_HW_INTERFACE_H
#define BRITTANY_TEMPERATURE_SENSOR_HW_INTERFACE_H

#include <string>
#include "../ComponentHw.h"
#include "../feature/OnePin.h"
#include "../feature/Temperature.h"

/**
 * @brief An interface to create a component that represents a sensor that can
 * obtain temperature(air) values.
 */
class TemperatureSensorHwInterface :
    public ComponentHw,
    public OnePin,
    public Temperature{

public:

    TemperatureSensorHwInterface(std::string id, uint8_t pin) :
        ComponentHw(id),
        OnePin(pin),
        Temperature() {

    };

};

#endif //BRITTANY_TEMPERATURE_SENSOR_HW_INTERFACE_H