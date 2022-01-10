#include "DHT22SensorHw.h"

DHT22SensorHw::DHT22SensorHw(std::string id, uint8_t pin) : TempHumHwInterface(id, pin), dht(pin, DHT22) {
    dht.begin();
}

std::optional<float> DHT22SensorHw::temperatureCelsius() {
    float temp = dht.readTemperature();
    return isnan(temp) ? std::nullopt : std::optional(temp);
}

std::optional<float> DHT22SensorHw::temperatureKelvin() {
    std::optional<float> tempC = temperatureCelsius();
    if(tempC.has_value()){
        return std::optional(Temperature::fromCToK(tempC.value()));
    }
    return std::nullopt;
}

std::optional<float> DHT22SensorHw::temperatureFahrenheit() {
    float temp = dht.readTemperature(true);
    return isnan(temp) ? std::nullopt : std::optional(temp);
}

std::optional<float> DHT22SensorHw::humidity() {
    float humidity = dht.readHumidity();
    return isnan(humidity) ? std::nullopt : std::optional(humidity);
}