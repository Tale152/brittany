#include "Edge.h"
#include "modules/Module.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"
#include "thing-descriptor/td_util.h"

using namespace TD;

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
    Json::Value td;
    td[key(Key::CONTEXT)] = value(Key::CONTEXT);
    td["id"] = "http://" + ip + ":" + std::to_string(port);
    td["title"] = "Mock Title";
    //Security
    Json::Value no_sec_obj;
    no_sec_obj[key(Key::SECURITY_DEFINITIONS_SCHEME)] = value(Key::SECURITY_DEFINITIONS_SCHEME);
    no_sec_obj[key(Key::SECURITY_DEFINITIONS_IN)] = value(Key::SECURITY_DEFINITIONS_IN);
    Json::Value security_def_obj;
    security_def_obj[value(Key::SECURITY)] = no_sec_obj;
    td[key(Key::SECURITY_DEFINITIONS)] = security_def_obj;
    td[key(Key::SECURITY)][0] = value(Key::SECURITY);
    return td;
}
