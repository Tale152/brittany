#ifndef BRITTANY_HUMIDITY_SENSOR_HW_INTERFACE_H
#define BRITTANY_HUMIDITY_SENSOR_HW_INTERFACE_H

#include <string>
#include "../ComponentHw.h"
#include "../feature/OnePin.h"
#include "../feature/Humidity.h"


/**
 * @brief An interface to create a component that represents a sensor that can
 * obtain humidity(air) values.
 */
class HumiditySensorHwInterface :
    public ComponentHw,
    public OnePin,
    public Humidity {

public:

    HumiditySensorHwInterface(std::string id, uint8_t pin) :
        ComponentHw(id),
        OnePin(pin),
        Humidity() {

    };

};

#endif //BRITTANY_HUMIDITY_SENSOR_HW_INTERFACE_H