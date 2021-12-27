#ifndef BRITTANY_FEATURE_TEMPERATURE_H
#define BRITTANY_FEATURE_TEMPERATURE_H

/**
 * @brief Feature of a class that can return a temperature value.
 */
class Temperature {

public:

    /**
     * @return float Get the temperature using the Celsius unit.
     */
    virtual float temperatureCelsius() = 0;

    /**
     * @return float Get the temperature using the Kelvin unit.
     */
    virtual float temperatureKelvin() = 0;

    /**
     * @return float Get the temperature using the Fahrenheit unit.
     */
    virtual float temperatureFahrenheit() = 0;

};

#endif //BRITTANY_FEATURE_TEMPERATURE_H