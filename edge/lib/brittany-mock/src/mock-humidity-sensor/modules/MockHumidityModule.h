#ifndef BRITTANY_MOCK_HUMIDITY_MODULE_H
#define BRITTANY_MOCK_HUMIDITY_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"
#include "mock-humidity-sensor/hw/MockHumiditySensorHw.h"
#include "mock-humidity-sensor/operation-handler/MockHumidityHandler.h"
#include "modules/ComponentModule.h"
#include "modules/ModuleNames.h"

#define MOCK_HUMIDITY_HANDLER_NAME "humidity"

class MockHumidityModule : public ComponentModule<MockHumiditySensorHw> {

public:

    MockHumidityModule(std::list<MockHumiditySensorHw*> components)
    : ComponentModule<MockHumiditySensorHw>(module_as_string(ModuleNames::Humidity), components) {
        _handlers.push_back(
            new MockHumidityHandler(
                MOCK_HUMIDITY_HANDLER_NAME,
                as_route(MOCK_HUMIDITY_HANDLER_NAME),
                components
            )
        );
    };

};

#endif //BRITTANY_MOCK_HUMIDITY_MODULE_H