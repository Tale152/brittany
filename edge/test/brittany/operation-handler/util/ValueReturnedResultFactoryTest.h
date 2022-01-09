#include <unity.h>
#include "operation-handler/interfaces/util/ValueReturnedResult.h"
#include "operation-handler/interfaces/util/ValueReturnedResultFactory.h"

template <class T>

void test_value_returned_result_factory_no_value(ValueReturnedResult<T> r, int code, std::string message) {
    TEST_ASSERT_EQUAL(code, r.code());
    TEST_ASSERT_FALSE(r.value().has_value());
    TEST_ASSERT_TRUE(r.message().has_value());
    TEST_ASSERT_EQUAL_STRING(
        message.c_str(),
        r.message().value().c_str()
    );
}

void test_value_returned_result_factory_not_found() {
    test_value_returned_result_factory_no_value(
        ValueReturnedResultFactory<int>::NotFoundResult(),
        HttpStatus::NotFound,
        phrase(ContentResult::ResourceNotFound)
    );
}

void test_value_returned_result_factory_bad_request() {
    test_value_returned_result_factory_no_value(
        ValueReturnedResultFactory<int>::BadRequestResult(),
        HttpStatus::BadRequest,
        phrase(ContentResult::BadRequest)
    );
}

void test_ValueReturnedResultFactoryTest(){
    RUN_TEST(test_value_returned_result_factory_not_found);
    RUN_TEST(test_value_returned_result_factory_bad_request);
}
 