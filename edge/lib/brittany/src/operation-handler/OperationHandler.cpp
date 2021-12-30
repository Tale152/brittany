#include "OperationHandler.h"

OperationHandler::OperationHandler(std::string name, std::string path, OperationType operationType) {
    _name = name;
    _path = path;
    _operationType = operationType;
}

std::string OperationHandler::name() {
    return _name;
}

std::string OperationHandler::path() {
    return _path;
}

OperationType OperationHandler::operationType() {
    return _operationType;
}
