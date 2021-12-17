#include "Edge.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"

Edge::Edge(std::list<OperationHandler*> operations) {
    _operations = operations;
}

OperationHandlerResult Edge::execute(std::string route, Json::Value args) {
    for(OperationHandler* h: _operations){
        if(h -> path() == route) {
            return h -> handle(args);
        }
    }
    return OperationHandlerResult(
        HttpStatus::NotFound,
        Json::Value(phrase(ContentResult::ResourceNotFound))
    );
}

std::list<std::string> Edge::availablePaths() {
    std::list<std::string> paths;
    for(OperationHandler* h : _operations) {
        paths.push_back(h -> path());
    }
    return paths;
}

ThingDescriptor Edge::thingDescriptor() {
    return ThingDescriptor();
}
