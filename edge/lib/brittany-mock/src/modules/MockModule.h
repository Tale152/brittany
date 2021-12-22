#ifndef BRITTANY_MOCK_MODULE_H
#define BRITTANY_MOCK_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"
#include "../operation-handler/MockOperationHandler.h"
#include "modules/Module.h"

#define OPERATION_HANDLER_IN_MOCK_MODULE_PATH "/value"

/**
 * @brief Mock Module that contains only a MockOperationHandler.
 */
class MockModule : public Module {

public:

    MockModule(std::string name): Module(name) {
        _handlers.push_back(
            new MockOperationHandler(OPERATION_HANDLER_IN_MOCK_MODULE_PATH)
        );
    };

};

#endif //BRITTANY_MOCK_COMPONENT_MODULE_H