#include "Module.h"
#include <cstdarg>

Module::Module(std::string name) {
    _name = name;
}

std::list<OperationHandler*> Module::handlers() {
    return _handlers;
}

std::string Module::name() {
    return _name;
}
