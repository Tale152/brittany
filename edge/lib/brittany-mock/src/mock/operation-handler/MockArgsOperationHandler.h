#ifndef BRITTANY_MOCK_ARGS_OPERATION_HANDLER_H
#define BRITTANY_MOCK_ARGS_OPERATION_HANDLER_H

#include <string>
#include <json/json.h>
#include "operation-handler/OperationHandlerResult.h"
#include "operation-handler/OperationHandler.h"
#include "HttpStatusCodes_C++.h"
#include "json_util.h"

/**
 * @brief Class that represents a mock OperationHandler that sends back
 *        the arguments as a JSON string used only for testing purposes.
 */
class MockArgsOperationHandler: public OperationHandler {

public:

    MockArgsOperationHandler(std::string name, std::string path) :
        OperationHandler(name, path, OperationType::PROPERTY, Type::INTEGER) {

    };

    OperationHandlerResult handle(Json::Value args) {
        const std::string output = stringify(args);
        stdOutStrategy(output.c_str());
        return OperationHandlerResult(HttpStatus::OK, output);
    };

private:

    /**
     * @brief Describe how to print to the std output the content.
     * 
     * @param content The content to print on the std output.
     */
    virtual void stdOutStrategy(std::string content) = 0;

};

#endif //BRITTANY_OPERATION_HANDLER_H