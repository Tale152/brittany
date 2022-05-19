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

#ifndef BRITTANY_FEATURE_HUMIDITY_H
#define BRITTANY_FEATURE_HUMIDITY_H

#include <optional>

/**
 * @brief Feature of a class that can return a humidity value.
 */
class Humidity {

public:

    /**
     * @return float Get the humidity percentage. Return empty if the operation fails.
     */
    virtual std::optional<float> humidity() = 0;

};

#endif //BRITTANY_FEATURE_HUMIDITY_H