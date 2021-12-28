#ifndef BRITTANY_DIGITAL_LIGHT_HW_H
#define BRITTANY_DIGITAL_LIGHT_HW_H

#include "hw/interfaces/TempHumHwInterface.h"
#include <string>
#include <DHT.h>

/**
 * @brief Concrete implementation of a DHT22 component.
 * 
 */
class MockTempHumSensorHw : public TempHumHwInterface {

public:

    MockTempHumSensorHw(std::string id, uint8_t pin) : dht(pin, DHT22) {

    };

    std::optional<float> temperatureCelsius() {

    };

    std::optional<float> temperatureKelvin() {

    };

    std::optional<float> temperatureFahrenheit() {

    };

    std::optional<float> humidity() {

    };

private:

    DHT dht;

};
#endif //BRITTANY_DIGITAL_LIGHT_HW_H
