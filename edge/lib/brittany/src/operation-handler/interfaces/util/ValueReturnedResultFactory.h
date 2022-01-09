#ifndef BRITTANY_VALUE_RETURNED_RESULT_FACTORY_H
#define BRITTANY_VALUE_RETURNED_RESULT_FACTORY_H

#include "HttpStatusCodes_C++.h"
#include <optional>
#include "util.h"

template <typename T>

class ValueReturnedResultFactory {

public:

    static ValueReturnedResult<T> NotFoundResult() {
        return ValueReturnedResult<T>(
                HttpStatus::NotFound,
                std::nullopt,
                phrase(ContentResult::ResourceNotFound)
        );
    }

};

#endif //BRITTANY_VALUE_RETURNED_RESULT_FACTORY_H
