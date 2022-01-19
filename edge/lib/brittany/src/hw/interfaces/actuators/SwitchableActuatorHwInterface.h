#ifndef BRITTANY_SWITCHABLE_ACTUATOR_HW_INTERFACE_H
#define BRITTANY_SWITCHABLE_ACTUATOR_HW_INTERFACE_H

#include <string>
#include "hw/ComponentHw.h"
#include "hw/feature/Switchable.h"

/**
 * @brief An interface to create a component that represent an actuator that can be turned on and off.
 */
class SwitchableActuatorHwInterface : public ComponentHw, public Switchable {

public:

    /**
     * @brief Construct a new Switchable Actuator Hw Interface object.
     * 
     * @param id 
     */
    SwitchableActuatorHwInterface(std::string id) :
        ComponentHw(id),
        Switchable() {

    };

};

#endif //BRITTANY_SWITCHABLE_ACTUATOR_HW_INTERFACE_H