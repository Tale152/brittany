#ifndef BRITTANY_VALUE_RETURNED_RESULT_FACTORY_H
#define BRITTANY_VALUE_RETURNED_RESULT_FACTORY_H

#include "HttpStatusCodes_C++.h"
#include <optional>
#include "util.h"

template <typename T>

class ValueReturnedResultFactory {

public:

    static ValueReturnedResult<T> OkWithValueResult(T value) {
        return ValueReturnedResult<T>(HttpStatus::OK, value);
    }

    static ValueReturnedResult<T> NotFoundResult() {
        return ValueReturnedResult<T>(
                HttpStatus::NotFound,
                std::nullopt,
                phrase(ContentResult::ResourceNotFound)
        );
    }

    static ValueReturnedResult<T> BadRequestResult() {
        return ValueReturnedResult<T>(
                HttpStatus::BadRequest,
                std::nullopt,
                phrase(ContentResult::BadRequest)
        );
    }

};

#endif //BRITTANY_VALUE_RETURNED_RESULT_FACTORY_H
