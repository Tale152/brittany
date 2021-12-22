#include "ComponentModule.h"

template <class T>

ComponentModule<T>::ComponentModule(std::string name, std::list<T*> components): Module(name) {
    //does nothing
}