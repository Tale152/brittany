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

#ifndef BRITTANY_TD_UTIL_H
#define BRITTANY_TD_UTIL_H

#include <string>
#include <tuple>

namespace TD {

    enum Key {
        CONTEXT = 0,
        SECURITY_DEFINITIONS = 1,
        SECURITY_DEFINITIONS_SCHEME = 2,
        SECURITY_DEFINITIONS_IN = 3,
        SECURITY = 4
    };

    std::tuple<const char *, const char*> td[] = {
        std::make_tuple("@context", "https://www.w3.org/2019/wot/td/v1"),
        std::make_tuple("securityDefinitions", "no_sec"),
        std::make_tuple("scheme", "nosec"),
        std::make_tuple("in", "header"),
        std::make_tuple("security", "no_sec")
    };

    std::string key(Key key) {
        return std::get<0>(td[key]);
    }
        
    std::string value(Key key) {
        return std::get<1>(td[key]);
    } 

}

#endif //BRITTANY_TD_UTIL_H