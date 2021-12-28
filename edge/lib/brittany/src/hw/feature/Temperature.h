#ifndef BRITTANY_FEATURE_TEMPERATURE_H
#define BRITTANY_FEATURE_TEMPERATURE_H

#include <optional>

/**
 * @brief Feature of a class that can return a temperature value.
 */
class Temperature {

public:

    /**
     * @return float Get the temperature using the Celsius unit. Return empty if the
     * operation fails.
     */
    virtual std::optional<float> temperatureCelsius() = 0;

    /**
     * @return float Get the temperature using the Kelvin unit. Return empty if the
     * operation fails.
     */
    virtual std::optional<float> temperatureKelvin() = 0;

    /**
     * @return float Get the temperature using the Fahrenheit unit. Return empty if the
     * operation fails.
     */
    virtual std::optional<float> temperatureFahrenheit() = 0;

public:

    static float fromCToF(float c) {
        return c * 1.8 + 32;
    };

    static float fromCToK(float c) {
        return c + 273.15;
    };

};

#endif //BRITTANY_FEATURE_TEMPERATURE_H