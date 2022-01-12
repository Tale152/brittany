#ifndef BRITTANY_TEMPERATURE_SENSOR_HW_INTERFACE_H
#define BRITTANY_TEMPERATURE_SENSOR_HW_INTERFACE_H

#include <string>
#include "hw/ComponentHw.h"
#include "hw/feature/Temperature.h"

/**
 * @brief An interface to create a component that represents a sensor that can
 * obtain temperature(air) values.
 */
class TemperatureSensorHwInterface :
    public ComponentHw,
    public Temperature{

public:

    TemperatureSensorHwInterface(std::string id) :
        ComponentHw(id),
        Temperature() {

    };

};

#endif //BRITTANY_TEMPERATURE_SENSOR_HW_INTERFACE_H