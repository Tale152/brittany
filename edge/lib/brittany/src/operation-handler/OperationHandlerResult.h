#ifndef BRITTANY_OPERATION_HANDLER_RESULT_H
#define BRITTANY_OPERATION_HANDLER_RESULT_H

#include "json/json.h"

class OperationHandlerResult {

public:

    OperationHandlerResult(int code, Json::Value content);

    int code();

    Json::Value content();

private:

    int _code;
    Json::Value _content;
};

#endif //BRITTANY_OPERATION_HANDLER_RESULT_H