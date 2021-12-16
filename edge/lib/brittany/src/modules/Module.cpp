#include "Module.h"
#include <cstdarg>

Module::Module() {
    //does nothing
}

std::list<OperationHandler*> Module::handlers() {
    return _handlers;
}