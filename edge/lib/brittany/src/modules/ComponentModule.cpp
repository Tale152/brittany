#include "ComponentModule.h"

template <class T>
ComponentModule<T>::ComponentModule(std::string name, std::list<T*> components): Module(name) {
    for(T* t : components) {
       _components.push_back(ComponentHw(t -> id()));
    }
}

template <class T>
std::list<ComponentHw> ComponentModule<T>::components() {
    return _components;
}
