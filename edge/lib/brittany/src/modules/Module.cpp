#include "Module.h"
#include <cstdarg>

template<class T>
Module<T>::Module(std::list<T*> handlers) {
    //does nothing
}

template<class T>
std::list<OperationHandler*> Module<T>::handlers() {
    return _handlers;
}