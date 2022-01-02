#ifndef BRITTANY_THING_DESCRIPTOR_BUILDER_H
#define BRITTANY_THING_DESCRIPTOR_BUILDER_H

#include "td_util.h"
#include "json/json.h"
#include "modules/Module.h"
#include "modules/ComponentModule.h"
#include "modules/ComponentModule.cpp"
#include "hw/ComponentHw.h"
#include <string>

using namespace TD;

class ThingDescriptorBuilder {

public:

    static Json::Value build(std::string ip, int port, std::list<Module*> modules) {
        Json::Value td;
        add_context(td);
        add_id(td, ip, port);
        add_title(td);
        add_security(td);
        add_modules(td, modules);
        add_href(td, ip, port, modules);
        return td;
    };

private:

    static void add_context(Json::Value &td) { 
        td[key(Key::CONTEXT)] = value(Key::CONTEXT);
    }

    static void add_title(Json::Value &td) { 
        td["title"] = "Mock Title";
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
        int i, j = 0;
        for(Module* m : modules) {
            td["modules"][0]["module"] = m -> name();
            ComponentModule<ComponentHw>* cm = static_cast<ComponentModule<ComponentHw>*>(m);
            j = 0;
            for(ComponentHw h : cm -> components()) {
                td["modules"][0]["components"][j++] = h.id();
            }
            i++; 
        }
    }

    static void add_href(Json::Value &td, std::string ip, int port, std::list<Module*> modules) {
        for(Module* m : modules) {
            for(OperationHandler* h : m -> handlers()) {
                ComponentModule<ComponentHw>* cm = static_cast<ComponentModule<ComponentHw>*>(m);
                for(ComponentHw c : cm -> components()) {
                    Json::Value action;
                    action["module"] = m -> name();
                    action["forms"][0]["href"] =
                        std::string("http://") + ip + ":" + std::to_string(port) + h -> path() + "?id=" + c.id();
                    action["forms"][0]["contentType"] = "application/json";
                    std::string objectName;
                    switch (h -> operationType())
                    {
                    case OperationType::ACTION:
                        objectName = "actions";
                        break;
                    case OperationType::PROPERTY:
                        objectName = "properties";
                        break;
                    case OperationType::EVENT:
                        objectName = "events";
                        break;
                    }
                    std::string name = h -> name();
                    if(cm->components().size() != 1) {
                        name += "-" + c.id();
                    }
                    td[objectName][name] = action;
                } 
            }
        }
        
    }

};


#endif //BRITTANY_THING_DESCRIPTOR_BUILDER_H