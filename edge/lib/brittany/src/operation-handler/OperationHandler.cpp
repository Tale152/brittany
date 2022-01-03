#include "OperationHandler.h"

OperationHandler::OperationHandler(
    std::string name,
    std::string path,
    OperationType operationType,
    Type outputType
) {
    _name = name;
    _path = path;
    _operationType = operationType;
    _outputType = outputType;
}

std::string OperationHandler::name() {
    return _name;
}

std::string OperationHandler::path() {
    return _path;
}

Type OperationHandler::outputType() {
    return _outputType;
}

OperationType OperationHandler::operationType() {
    return _operationType;
}
