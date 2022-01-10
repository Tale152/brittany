#ifndef BRITTANY_MOCK_TEMP_HUM_SENSOR_HW_H
#define BRITTANY_MOCK_TEMP_HUM_SENSOR_HW_H

#include "hw/interfaces/TempHumHwInterface.h"
#include <string>
#include <optional>

/**
 * @brief Mock Implemenattion of a Mock temperature and Humidity sensor.
 * 
 */
class MockTempHumSensorHw : public TempHumHwInterface {

public:

    /**
     * @brief Construct a new Mock Temp Hum Sensor Hw object
     * 
     * @param id the hw id.
     * @param pin the hw pin.
     * @param celsius_value the mock value to return as celsius.
     * @param humidity_value the mock value to return as humidity.
     */
    MockTempHumSensorHw(
        std::string id,
        uint8_t pin,
        std::optional<float> celsius_value,
        std::optional<float> humidity_value) : TempHumHwInterface(id, pin) {
        _celsius_value = celsius_value;
        _humidity_value = humidity_value;
    };

    std::optional<float> temperatureCelsius() {
        return _celsius_value;
    };

    std::optional<float> temperatureKelvin() {
        return temperatureCelsius().has_value()
            ? std::optional(Temperature::fromCToK(temperatureCelsius().value()))
            : std::nullopt;
    };

    std::optional<float> temperatureFahrenheit() {
        return temperatureCelsius().has_value()
            ? std::optional(Temperature::fromCToF(temperatureCelsius().value()))
            : std::nullopt;
    };

    std::optional<float> humidity() {
        return _humidity_value;
    };
    
private:

    std::optional<float> _celsius_value;
    std::optional<float> _humidity_value;

};
#endif //BRITTANY_MOCK_TEMP_HUM_SENSOR_HW_H
