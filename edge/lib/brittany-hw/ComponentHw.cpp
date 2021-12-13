#include "ComponentHw.h"

ComponentHw::ComponentHw(std::string id) {
    _id = id;
}

std::string ComponentHw::id() {
    return _id;
}

