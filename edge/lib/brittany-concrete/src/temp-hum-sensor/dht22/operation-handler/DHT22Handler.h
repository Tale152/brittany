#ifndef BRITTANY_DHT22_HANDLER_H
#define BRITTANY_DHT22_HANDLER_H

#include <string>
#include <list>
#include "operation-handler/interfaces/ValueReturnedAfterActionHandlerInterface.h"
#include "temp-hum-sensor/dht22/hw/DHT22SensorHw.h"

class DHT22Handler : public ValueReturnedAfterActionHandlerInterface<float> {

public:

    DHT22Handler(std::string name, std::string path, std::list<DHT22SensorHw*> components)
    : ValueReturnedAfterActionHandlerInterface<float> (name, path, OperationType::PROPERTY, Type::NUMBER) {
        _components = components;
    };

private:

    std::optional<float> retrieveValue(Json::Value args) {
        std::optional<DHT22SensorHw*> oc = find_by_id(_components, args["id"].asCString());
        if(oc.has_value()) {
            std::optional<float> opt_value = sub_operation(oc.value(), args);
            if(opt_value.has_value()) {
                return opt_value.value();
            }
        }
        return std::nullopt;
    }

    virtual std::optional<float> sub_operation(DHT22SensorHw* hw, Json::Value args) = 0;

    std::list<DHT22SensorHw*> _components;
};

#endif //BRITTANY_DHT22_HANDLER_H
