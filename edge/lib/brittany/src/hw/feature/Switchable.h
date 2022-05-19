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

#ifndef BRITTANY_FEATURE_SWITCHABLE_H
#define BRITTANY_FEATURE_SWITCHABLE_H

/**
 * @brief Feature of a class that can be turned on and off and has an internal state.
 */
class Switchable {

public:

    /**
     * @brief the turn on operation.
     */
    virtual void on() = 0;

    /**
     * @brief the turn off operation.
     */
    virtual void off() = 0;

    /**
     * @brief check if the state is on or off.
     * 
     * @return true if state is on.
     * @return false if state is off.
     */
    virtual bool isOn() = 0;

};

#endif //BRITTANY_FEATURE_SWITCHABLE_H