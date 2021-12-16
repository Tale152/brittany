#ifndef BRITTANY_MOCK_MODULE_H
#define BRITTANY_MOCK_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"
#include "../operation-handler/MockOperationHandler.h"
#include "modules/Module.h"

#define OPERATION_HANDLER_IN_MOCK_MODULE_PATH "/value"

class MockModule : public Module {

public:

    MockModule(): Module() {
        _handlers.push_back(
            new MockOperationHandler(OPERATION_HANDLER_IN_MOCK_MODULE_PATH)
        );
    };

};

#endif //BRITTANY_MOCK_COMPONENT_MODULE_H