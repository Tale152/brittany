#include "Edge.h"
#include "modules/Module.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"
#include "thing-descriptor/ThingDescriptorBuilder.h"

Edge::Edge(std::list<Module*> modules) {
    _modules = modules;
}

OperationHandlerResult Edge::execute(std::string route, Json::Value args) {
    for(Module* m : _modules) {
        for(OperationHandler* h: m -> handlers()) {
            if(h -> path() == route) {
                return h -> handle(args);
            }
        }
    }
    return OperationHandlerResult(
        HttpStatus::NotFound,
        Json::Value(phrase(ContentResult::ResourceNotFound))
    );
}

std::list<std::string> Edge::availablePaths() {
    std::list<std::string> paths;
    for(Module* m : _modules) {
        for(OperationHandler* h: m -> handlers()) {
            paths.push_back(h -> path());
        }
    }
    return paths;
}

Json::Value Edge::thingDescriptor(std::string ip, int port) {
    return ThingDescriptorBuilder::build(ip, port, _modules);
}
