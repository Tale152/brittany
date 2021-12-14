#include "OperationHandler.h"

OperationHandler::OperationHandler(std::string path) {
    _path = path;
}

std::string OperationHandler::path() {
    return _path;
}
