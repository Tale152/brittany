#include "EdgeBuilder.h"

EdgeBuilder::EdgeBuilder() {
    //does nothing
}

void EdgeBuilder::addModule(Module module) {
    _modules.push_back(module);
}

void EdgeBuilder::addAllModules(std::list<Module> modules) {
    for(Module m : modules) {
        addModule(m);
    }
}

Edge* EdgeBuilder::build() {
    std::list<OperationHandler*> handlers;
    for(Module m : _modules) {
        for(OperationHandler* h : m.handlers()) {
            handlers.push_back(h);
        }
    }
    return new Edge(handlers);
}