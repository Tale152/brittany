#ifndef BRITTANY_OPERATION_HANDLER_RESULT_H
#define BRITTANY_OPERATION_HANDLER_RESULT_H

#include "json/json.h"

/**
 * @brief A class that wraps the results information of an OperationHandler.
 */
class OperationHandlerResult {

public:

    /**
     * @brief Construct a new Operation Handler Result object.
     * 
     * @param code the code of the result.
     * @param content a json value containing information about the result.
     */
    OperationHandlerResult(int code, Json::Value content);

    /**
     * @brief Return the result code.
     * 
     * @return int a code that identify what occurence happened executing the OperationHandler.
     */
    int code();

    /**
     * @brief Return the Json value.
     * 
     * @return Json::Value a json value that contains information of what happened when executing the OperationHandler.
     */
    Json::Value content();

private:

    int _code;
    Json::Value _content;
};

#endif //BRITTANY_OPERATION_HANDLER_RESULT_H