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

#ifndef BRITTANY_VALUE_RETURNED_RESULT_FACTORY_H
#define BRITTANY_VALUE_RETURNED_RESULT_FACTORY_H

#include "HttpStatusCodes_C++.h"
#include <optional>
#include "util.h"

template <typename T>

/**
 * @brief Factory class to create specifics ValueReturnedResult.
 * 
 */
class ValueReturnedResultFactory {

public:

    /**
     * @brief Return a ValueReturnedResult with a value and without a message with OK as code.
     * 
     * @param value the value to insert in the ValueReturnedResult.
     * @return ValueReturnedResult<T> a new ValueReturnedResult.
     */
    static ValueReturnedResult<T> OkWithValueResult(T value) {
        return ValueReturnedResult<T>(HttpStatus::OK, value);
    }

    /**
     * @brief Return a ValueReturnedResult without value, with a message specifiyng that no
     * resource was found and with NotFound as code.
     * 
     * @return ValueReturnedResult<T> a new ValueReturnedResult.
     */
    static ValueReturnedResult<T> NotFoundResult() {
        return ValueReturnedResult<T>(
                HttpStatus::NotFound,
                std::nullopt,
                phrase(ContentResult::ResourceNotFound)
        );
    }

    /**
     * @brief Return a ValueReturnedResult without value, with a message specifiyng that a bad
     * request was sent and with BadRequest as code.
     * 
     * @return ValueReturnedResult<T>  a new ValueReturnedResult.
     */
    static ValueReturnedResult<T> BadRequestResult() {
        return ValueReturnedResult<T>(
                HttpStatus::BadRequest,
                std::nullopt,
                phrase(ContentResult::BadRequest)
        );
    }

};

#endif //BRITTANY_VALUE_RETURNED_RESULT_FACTORY_H
