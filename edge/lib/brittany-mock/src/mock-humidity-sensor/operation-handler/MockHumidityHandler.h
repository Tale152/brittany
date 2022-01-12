#ifndef MOCK_HUMIDITY_HANDLER_H
#define MOCK_HUMIDITY_HANDLER_H

#include <string>
#include <list>
#include "operation-handler/interfaces/RetrieveValueFromComponentInterface.h"
#include "mock-humidity-sensor/hw/MockHumiditySensorHw.h"

class MockHumidityHandler : public RetrieveValueFromComponentInterface<MockHumiditySensorHw, float> {

public:

    MockHumidityHandler(std::string name, std::string path, std::list<MockHumiditySensorHw*> components)
    : RetrieveValueFromComponentInterface<MockHumiditySensorHw, float> (name, path, components) {

    };

private:

    std::optional<float> sub_operation(MockHumiditySensorHw* hw, Json::Value args) {
        return hw-> humidity();
    }

};

#endif // MOCK_HUMIDITY_HANDLER_H