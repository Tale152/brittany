#ifndef BRITTANY_DHT22_SENSOR_HW_H
#define BRITTANY_DHT22_SENSOR_HW_H

#include "hw/interfaces/TempHumHwInterface.h"
#include <string>
#include <DHT.h>
#include <DHT_U.h>
#include <optional>
#include <Adafruit_Sensor.h>

/**
 * @brief Concrete implementation of a DHT22 component.
 * 
 */
class DHT22SensorHw : public TempHumHwInterface {

public:

    /**
     * @brief Construct a new DHT22SensorHw object.
     * 
     * @param id the hw id.
     * @param pin the data pin of the DHT22.
     */
    DHT22SensorHw(std::string id, uint8_t pin);

    std::optional<float> temperatureCelsius();

    std::optional<float> temperatureKelvin();

    std::optional<float> temperatureFahrenheit();

    std::optional<float> humidity();

private:

    DHT dht;

};
#endif //BRITTANY_DHT22_SENSOR_HW_H
