#ifndef RETRIEVE_VALUE_FROM_COMPONENT_INTERFACE_H
#define RETRIEVE_VALUE_FROM_COMPONENT_INTERFACE_H

#include <string>
#include <list>
#include "operation-handler/interfaces/ValueReturnedAfterActionHandlerInterface.h"

template <class C, class T>

class RetrieveValueFromComponentInterface : public ValueReturnedAfterActionHandlerInterface<T> {

public:

    /**
     * @brief Construct a new Retrieve Value From Component Interface object.
     * 
     * @param name the name of the operation handler.
     * @param path the path used for the operation handler.
     * @param operationType  the operation type.
     * @param returnedType the returned type.
     * @param components the list of components.
     */
    RetrieveValueFromComponentInterface(
        std::string name,
        std::string path,
        OperationType operationType,
        Type returnedType,
        std::list<C*> components
    )
    : ValueReturnedAfterActionHandlerInterface<T> (
        name,
        path,
        operationType,
        returnedType
    ) {
        _components = components;
    };

    /**
     * @brief Construct a new Retrieve Value From Component Interface object.
     *        Simplified Constructor that set the handler to a property and return a number.
     * 
     * @param name 
     * @param path 
     * @param components 
     */
    RetrieveValueFromComponentInterface(
        std::string name,
        std::string path,
        std::list<C*> components
    )
    : ValueReturnedAfterActionHandlerInterface<T> (
        name,
        path,
        OperationType::PROPERTY,
        Type::NUMBER
    ) {
        _components = components;
    };

private:

    std::optional<T> retrieveValue(Json::Value args) {
        std::optional<C*> oc = find_by_id(_components, args["id"].asCString());
        if(oc.has_value()) {
            std::optional<T> opt_value = sub_operation(oc.value(), args);
            if(opt_value.has_value()) {
                return opt_value.value();
            }
        }
        return std::nullopt;
    }

    virtual std::optional<T> sub_operation(C* hw, Json::Value args) = 0;

    std::list<C*> _components;
};

#endif //RETRIEVE_VALUE_FROM_COMPONENT_INTERFACE_H
