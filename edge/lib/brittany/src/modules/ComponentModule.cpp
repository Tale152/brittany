#include "ComponentModule.h"

template <class T>
ComponentModule<T>::ComponentModule(std::string name, std::list<T*> components): Module(name) {
    _components = components;
}

template <class T>
std::list<T*> ComponentModule<T>::components() {
    return _components;
}
