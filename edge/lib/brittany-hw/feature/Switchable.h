#ifndef BRITTANY_FEATURE_SWITCHABLE_H
#define BRITTANY_FEATURE_SWITCHABLE_H

/**
 * @brief Feature of a class that can be turned on and off and has an internal state.
 */
class Switchable {

public:

    /**
     * @brief the turn on operation.
     */
    virtual void on() = 0;

    /**
     * @brief the turn off operation.
     */
    virtual void off() = 0;

    /**
     * @brief check if the state is on or off.
     * 
     * @return true if state is on.
     * @return false if state is off.
     */
    virtual bool isOn() = 0;

};

#endif //BRITTANY_FEATURE_SWITCHABLE_H