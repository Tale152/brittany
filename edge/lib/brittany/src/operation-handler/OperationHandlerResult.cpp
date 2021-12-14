#include "OperationHandlerResult.h"

OperationHandlerResult::OperationHandlerResult(int code, Json::Value content) {
    _code = code;
    _content = content;
}

int OperationHandlerResult::code() {
    return _code;
}

Json::Value OperationHandlerResult::content() {
    return _content;
}
