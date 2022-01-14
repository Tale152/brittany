#ifndef BRITTANY_MOCK_HUMIDITY_MODULE_H
#define BRITTANY_MOCK_HUMIDITY_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"
#include "mock-humidity-sensor/hw/MockHumiditySensorHw.h"
#include "mock-humidity-sensor/operation-handler/MockHumidityHandler.h"
#include "modules/ComponentModule.h"
#include "modules/ModuleNames.h"

class MockHumidityModule : public ComponentModule<MockHumiditySensorHw> {

public:

    MockHumidityModule(std::list<MockHumiditySensorHw*> components)
    : ComponentModule<MockHumiditySensorHw>(module_as_string(ModuleNames::Humidity), components) {
        _handlers.push_back(new MockHumidityHandler(components));
    };

};

#endif //BRITTANY_MOCK_HUMIDITY_MODULE_H