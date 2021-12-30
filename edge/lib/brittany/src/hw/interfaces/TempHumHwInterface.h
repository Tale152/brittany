#ifndef BRITTANY_TEMP_HUM_SENSOR_HW_INTERFACE_H
#define BRITTANY_TEMP_HUM_SENSOR_HW_INTERFACE_H

#include <string>
#include "../ComponentHw.h"
#include "../feature/OnePin.h"
#include "../feature/Humidity.h"
#include "../feature/Temperature.h"

/**
 * @brief An interface to create a component that represents a sensor that can
 * obtain temperature(air) and humidity(air) values.
 */
class TempHumHwInterface :
    public ComponentHw,
    public OnePin,
    public Temperature,
    public Humidity {

public:

    TempHumHwInterface(std::string id, uint8_t pin) :
        ComponentHw(id),
        OnePin(pin),
        Temperature(),
        Humidity() {

    };

};

#endif //BRITTANY_TEMP_HUM_SENSOR_HW_INTERFACE_H