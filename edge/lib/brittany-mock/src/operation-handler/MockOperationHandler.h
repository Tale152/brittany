#ifndef BRITTANY_MOCK_OPERATION_HANDLER_H
#define BRITTANY_MOCK_OPERATION_HANDLER_H

#include <string>
#include <json/json.h>
#include "operation-handler/OperationHandlerResult.h"
#include "operation-handler/OperationHandler.h"
#include "HttpStatusCodes_C++.h"

/**
 * @brief Class that represents a mock OperationHandler used only for testing purposes.
 */
class MockOperationHandler: public OperationHandler {

public:

    MockOperationHandler(std::string path) : OperationHandler(path) {
        _value = 0;
    };

    virtual OperationHandlerResult handle(Json::Value args) {
        _value = _value + args.asInt();
        return OperationHandlerResult(HttpStatus::OK, Json::Value(_value));
    };

private:

    int _value;

};

#endif //BRITTANY_OPERATION_HANDLER_H