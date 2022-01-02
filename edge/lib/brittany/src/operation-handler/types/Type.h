#ifndef BRITTANY_OPERATION_TYPE_H
#define BRITTANY_OPERATION_TYPE_H

#include <string>

/**
 * @brief Describe the type of certain data, used to generate the Thing Descriptor.
 */
enum Type {
    OBJECT,
    ARRAY,
    STRING,
    NUMBER,
    INTEGER,
    BOOLEAN,
    NULL_TYPE
};

std::string type_to_string(Type type) {
    switch (type) {
        case OBJECT:
            return "object";
        case ARRAY:
            return "array";
        case STRING:
            return "string";
        case NUMBER:
            return "number";
        case INTEGER:
            return "integer";
        case BOOLEAN:
            return "boolean";
        case NULL_TYPE:
            return "null";
        default:
            return "null";
    }
}


#endif