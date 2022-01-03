#ifndef BRITTANY_MOCK_MODULE_H
#define BRITTANY_MOCK_MODULE_H

#include <list>
#include "operation-handler/OperationHandler.h"
#include "../operation-handler/MockOperationHandler.h"
#include "modules/Module.h"
#include "util.h"
#include "operation-handler/types/OperationType.h"

#define OPERATION_HANDLER_IN_MOCK_MODULE_NAME "value"

/**
 * @brief Mock Module that contains only a MockOperationHandler.
 */
class MockModule : public Module {

public:

    MockModule(std::string name): Module(name) {
        _handlers.push_back(
            new MockOperationHandler(
                OPERATION_HANDLER_IN_MOCK_MODULE_NAME,
                as_route(OPERATION_HANDLER_IN_MOCK_MODULE_NAME)
            )
        );
    };

};

#endif //BRITTANY_MOCK_COMPONENT_MODULE_H