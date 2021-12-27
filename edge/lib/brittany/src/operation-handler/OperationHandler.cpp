#include "OperationHandler.h"

OperationHandler::OperationHandler(std::string name, std::string path) {
    _name = name;
    _path = path;
}

std::string OperationHandler::name() {
    return _name;
}

std::string OperationHandler::path() {
    return _path;
}
