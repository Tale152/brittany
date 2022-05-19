/* * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BRITTANY_THING_DESCRIPTOR_BUILDER_H
#define BRITTANY_THING_DESCRIPTOR_BUILDER_H

#include "td_util.h"
#include "json/json.h"
#include "modules/Module.h"
#include "modules/ComponentModule.h"
#include "hw/ComponentHw.h"
#include <string>
#include <unordered_map>

using namespace TD;

class ThingDescriptorBuilder {

public:

    static Json::Value build(std::string ip, int port, std::string title, std::list<Module*> modules) {
        Json::Value td;
        add_context(td);
        add_id(td, ip, port);
        add_title(td, title);
        add_security(td);
        add_modules(td, modules);
        add_href(td, ip, port, modules);
        return td;
    };

private:

    static void add_context(Json::Value &td) { 
        td[key(Key::CONTEXT)] = value(Key::CONTEXT);
    }

    static void add_title(Json::Value &td, std::string title) { 
        td["title"] = title;
    }
        
    static void add_id(Json::Value &td, std::string ip, int port) { 
        td["id"] = "http://" + ip + ":" + std::to_string(port);
    }

    static void add_security(Json::Value &td) { 
        Json::Value no_sec_obj;
        no_sec_obj[key(Key::SECURITY_DEFINITIONS_SCHEME)] = value(Key::SECURITY_DEFINITIONS_SCHEME);
        no_sec_obj[key(Key::SECURITY_DEFINITIONS_IN)] = value(Key::SECURITY_DEFINITIONS_IN);
        Json::Value security_def_obj;
        security_def_obj[value(Key::SECURITY)] = no_sec_obj;
        td[key(Key::SECURITY_DEFINITIONS)] = security_def_obj;
        td[key(Key::SECURITY)][0] = value(Key::SECURITY);
    }

    static void add_modules(Json::Value &td, std::list<Module*> modules) {
        std::unordered_map<std::string, std::list<ComponentHw>> map;
        for(Module* m : modules) {
            ComponentModule<ComponentHw>* cm = static_cast<ComponentModule<ComponentHw>*>(m);
            std::list<ComponentHw> components;
            if(map.find(cm -> name()) == map.end()) {
                components = cm -> components();
            } else {
                components = map[cm -> name()];
                components.splice(components.end(), cm -> components());
            } 
            map.insert_or_assign(cm -> name(), components);
        }
        int i = 0;
        for(const std::pair<std::string, std::list<ComponentHw>> n : map) {
            td["modules"][i]["module"] = n.first.c_str();
            int j = 0;
            for(ComponentHw c : n.second) {
                td["modules"][i]["components"][j++] = c.id().c_str();
            }
            i++;
        }
    }

    static void add_href(Json::Value &td, std::string ip, int port, std::list<Module*> modules) {
        for(Module* m : modules) {
            for(OperationHandler* h : m -> handlers()) {
                ComponentModule<ComponentHw>* cm = static_cast<ComponentModule<ComponentHw>*>(m);
                for(ComponentHw c : cm -> components()) {
                    Json::Value object;
                    object["module"] = m -> name();
                    object["forms"][0]["href"] =
                        std::string("http://") + ip + ":" + std::to_string(port) + h -> path() + "?id=" + c.id();
                    object["forms"][0]["contentType"] = "application/json";
                    std::string objectName;
                    std::string name = h -> name() + "-" + c.id();
                    std::string type = type_to_string(h -> outputType());
                    switch (h -> operationType()) {
                    case OperationType::ACTION:
                        objectName = "actions";
                        object["output"]["type"] = type;
                        break;
                    case OperationType::PROPERTY:
                        objectName = "properties";
                        object["type"] = type;
                        break;
                    case OperationType::EVENT:
                        objectName = "events";
                        break;
                    }
                    td[objectName][name] = object;
                } 
            }
        }
        
    }

};


#endif //BRITTANY_THING_DESCRIPTOR_BUILDER_H