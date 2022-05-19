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

#ifndef BRITTANY_TYPE_H
#define BRITTANY_TYPE_H

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

inline std::string type_to_string(Type type) {
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

#endif // BRITTANY_TYPE_H