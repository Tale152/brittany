#include "Edge.h"
#include "HttpStatusCodes_C++.h"

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
        Json::Value("The requested resource does not exist.")
    );
}

ThingDescriptor Edge::thingDescriptor() {

}
