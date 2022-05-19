//
// Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "Edge.h"
#include "modules/Module.h"
#include "HttpStatusCodes_C++.h"
#include "util.h"
#include "thing-descriptor/ThingDescriptorBuilder.h"

Edge::Edge(std::string title, std::list<Module*> modules) {
    _title = title;
    _modules = modules;    
}

std::string Edge::title() {
    return _title;
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
    return ThingDescriptorBuilder::build(ip, port, _title, _modules);
}
