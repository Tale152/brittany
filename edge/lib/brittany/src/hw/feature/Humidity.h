#ifndef BRITTANY_FEATURE_HUMIDITY_H
#define BRITTANY_FEATURE_HUMIDITY_H

/**
 * @brief Feature of a class that can return a humidity value.
 */
class Humidity {

public:

    /**
     * @return float Get the humidity percentage.
     */
    virtual float humidity() = 0;

};

#endif //BRITTANY_FEATURE_HUMIDITY_H