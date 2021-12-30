#ifndef BRITTANY_DHT22_HANDLER_H
#define BRITTANY_DHT22_HANDLER_H

#include <string>
#include <list>
#include "operation-handler/interfaces/ValueReturnedHandlerInterface.h"
#include "temp-hum-sensor/hw/DHT22SensorHw.h"

class DHT22Handler : public ValueReturnedHandlerInterface<float> {

public:

    DHT22Handler(std::string name, std::string path, std::list<DHT22SensorHw*> components)
    : ValueReturnedHandlerInterface<float> (name, path, OperationType::PROPERTY) {
        _components = components;
    };

private:

    std::optional<float> operation(Json::Value args) {
        if(args.isMember("id")) {
            std::optional<DHT22SensorHw*> oc = find_by_id(_components, args["id"].asCString());
            if(oc.has_value()) {
                return sub_operation(oc.value(), args);
            }
            return std::nullopt; // failed to retrieve component
        }
        return std::nullopt; // id not found
    }


    virtual std::optional<float> sub_operation(DHT22SensorHw* hw, Json::Value args) = 0;

    std::list<DHT22SensorHw*> _components;
};

#endif //BRITTANY_DHT22_HANDLER_H
