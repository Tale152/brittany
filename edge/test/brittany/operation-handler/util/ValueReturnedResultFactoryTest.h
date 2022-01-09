#include <unity.h>
#include "operation-handler/interfaces/util/ValueReturnedResult.h"
#include "operation-handler/interfaces/util/ValueReturnedResultFactory.h"

void test_value_returned_result_factory_not_found() {
    ValueReturnedResult<int> r = ValueReturnedResultFactory<int>::NotFoundResult();
    TEST_ASSERT_EQUAL(HttpStatus::NotFound, r.code());
    TEST_ASSERT_FALSE(r.value().has_value());
    TEST_ASSERT_TRUE(r.message().has_value());
    TEST_ASSERT_EQUAL_STRING(
        phrase(ContentResult::ResourceNotFound).c_str(),
        r.message().value().c_str()
    );
}

void test_ValueReturnedResultFactoryTest(){
    RUN_TEST(test_value_returned_result_factory_not_found);
}
 