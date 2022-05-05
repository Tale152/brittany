#ifndef BRITTANY_DIGITAL_LIGHT_HW_INTERFACE_H
#define BRITTANY_DIGITAL_LIGHT_HW_INTERFACE_H

#include <string>
#include "../ComponentHw.h"
#include "../feature/OnePin.h"
#include "../feature/Switchable.h"

/**
 * @brief An interface to create a component that represent a digital light.
 */
class DigitalLightHwInterface : public ComponentHw, public Switchable {

public:

    /**
     * @brief Construct a new Digital Light Hw Interface object.
     * 
     * @param id the unique id of the component.
     */
    DigitalLightHwInterface(std::string id) :
        ComponentHw(id),
        Switchable() {

    };

};

#endif //BRITTANY_DIGITAL_LIGHT_HW_INTERFACE_H