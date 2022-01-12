#ifndef MOCK_TEMPERATURE_SENSOR_HW_H
#define MOCK_TEMPERATURE_SENSOR_HW_H

#include "hw/interfaces/sensors/TemperatureSensorHwInterface.h"

#define MOCK_MAX_TEMPERATURE_CELSIUS 40

/**
 * @brief Mock Implementation of a temperature sensor hw.
 */
class MockTemperatureSensorHw : public TemperatureSensorHwInterface {

public:

    /**
     * @brief Construct a new MockTemperatureSensorHw object.
     * 
     * @param id the hw id.
     */
    MockTemperatureSensorHw(std::string id) : TemperatureSensorHwInterface(id) { };

    std::optional<float> temperatureCelsius() {
        return random(0, MOCK_MAX_TEMPERATURE_CELSIUS);
    }

    std::optional<float> temperatureKelvin() {
        std::optional<float> tempC = temperatureCelsius();
        if(tempC.has_value()){
            return std::optional(Temperature::fromCToK(tempC.value()));
        }
        return std::nullopt;
    }

    std::optional<float> temperatureFahrenheit(){
        std::optional<float> tempC = temperatureCelsius();
        if(tempC.has_value()){
            return std::optional(Temperature::fromCToF(tempC.value()));
        }
        return std::nullopt;
    }

};
#endif //MOCK_TEMPERATURE_SENSOR_HW_H
