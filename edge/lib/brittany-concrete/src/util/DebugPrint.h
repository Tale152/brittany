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

#ifndef BRITTANY_CONCRETE_UTIL_H
#define BRITTANY_CONCRETE_UTIL_H

#include <string>
#include <Arduino.h>

/**
 * @brief Class used fro debug print purpose.
 * 
 */
class DebugPrint {

public:

    /**
     * @brief Construct a new Debug Print object.
     * 
     * @param debug specify if debug is enabled.
     */
    DebugPrint(bool debug) {
        _debug = debug;
    }

    /**
     * @brief Print on stdout with newline only if debug is enabled.
     * 
     * @param str 
     */
    void println(std::string str) {
        if(_debug) {
            Serial.println(str.c_str());
        }
    }

private:

    bool _debug;

};

#endif //BRITTANY_CONCRETE_UTIL_H