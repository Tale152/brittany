#include <unity.h>
#include "operation-handler/interfaces/util/ValueReturnedResult.h"

void test_value_returned_result_code(int expected, int actual) {
    TEST_ASSERT_EQUAL(expected, actual);
}

template <class T>
bool is_value_returned_result_value_present(std::optional<T> value) {
    return value.has_value();
}

template <class T>
void test_value_returned_result_value(T expected, T actual) {
    TEST_ASSERT_EQUAL(expected, actual);
}

bool is_value_returned_result_message_present(std::optional<std::string> value) {
    return is_value_returned_result_value_present<std::string>(value);
}

void test_value_returned_result_message(std::string expected, std::string actual) {
    TEST_ASSERT_EQUAL_STRING(expected.c_str(), actual.c_str());
} 

void test_value_returned_code_constructor() {
    ValueReturnedResult<int> res = ValueReturnedResult<int>(200);
    test_value_returned_result_code(200, res.code());
    TEST_ASSERT_FALSE(is_value_returned_result_value_present(res.value()));
    TEST_ASSERT_FALSE(is_value_returned_result_message_present(res.message()));
}


void test_value_returned_full_constructor() {
    ValueReturnedResult<int> res = ValueReturnedResult<int>(100, std::optional<int>(13), std::optional<std::string>("Ok."));
    test_value_returned_result_code(100, res.code());
    TEST_ASSERT_TRUE(is_value_returned_result_value_present(res.value()));
    TEST_ASSERT_TRUE(is_value_returned_result_message_present(res.message()));
     test_value_returned_result_value(13, res.value().value());
    test_value_returned_result_message("Ok.", res.message().value());
    
}

void test_ValueReturnedResultTest(){
    RUN_TEST(test_value_returned_code_constructor);
    RUN_TEST(test_value_returned_full_constructor);
}
