#ifndef BRITTANY_MOCK_TEMPERATURE_HANDLER_H
#define BRITTANY_MOCK_TEMPERATURE_HANDLER_H

#include <string>
#include <list>
#include "operation-handler/interfaces/RetrieveValueFromComponentInterface.h"
#include "mock-temperature-sensor/hw/MockTemperatureSensorHw.h"

class MockTemperatureHandler : public RetrieveValueFromComponentInterface<MockTemperatureSensorHw, float> {

public:

    MockTemperatureHandler(std::list<MockTemperatureSensorHw*> components)
        : RetrieveValueFromComponentInterface<MockTemperatureSensorHw, float> ("temperature", components) {

    };

private:

    std::optional<float> sub_operation(MockTemperatureSensorHw* hw, Json::Value args) {
        if(args.isMember("unit")) {
            if(args["unit"] == "C" || args["unit"] == "c") {
                return hw -> temperatureCelsius();
            } else if(args["unit"] == "K" || args["unit"] == "k") {
                return hw -> temperatureKelvin();
            } else if(args["unit"] == "F" || args["unit"] == "f") {
                return hw -> temperatureFahrenheit();
            }
            return std::nullopt;
        }
        return hw -> temperatureCelsius();
    }

};

#endif // BRITTANY_MOCK_TEMPERATURE_HANDLER_H