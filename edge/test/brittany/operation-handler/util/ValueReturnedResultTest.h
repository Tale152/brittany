#include <unity.h>
#include "operation-handler/interfaces/util/ValueReturnedResult.h"

#define VALUE_RETURNED_RESULT_CODE 100
#define VALUE_RETURNED_RESULT_VALUE 13
#define VALUE_RETURNED_RESULT_MESSAGE "OK."

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
    ValueReturnedResult<int> res = ValueReturnedResult<int>(VALUE_RETURNED_RESULT_CODE);
    test_value_returned_result_code(VALUE_RETURNED_RESULT_CODE, res.code());
    TEST_ASSERT_FALSE(is_value_returned_result_value_present(res.value()));
    TEST_ASSERT_FALSE(is_value_returned_result_message_present(res.message()));
}


void test_value_returned_result_is_correct(ValueReturnedResult<int> res) {
    test_value_returned_result_code(VALUE_RETURNED_RESULT_CODE, res.code());
    TEST_ASSERT_TRUE(is_value_returned_result_value_present(res.value()));
    TEST_ASSERT_TRUE(is_value_returned_result_message_present(res.message()));
    test_value_returned_result_value(VALUE_RETURNED_RESULT_VALUE, res.value().value());
    test_value_returned_result_message(VALUE_RETURNED_RESULT_MESSAGE, res.message().value()); 
}

void test_value_returned_full_constructor() {
    ValueReturnedResult<int> res = ValueReturnedResult<int>(
        VALUE_RETURNED_RESULT_CODE,
        std::optional<int>(VALUE_RETURNED_RESULT_VALUE),
        std::optional<std::string>(VALUE_RETURNED_RESULT_MESSAGE)
    );
    test_value_returned_result_is_correct(res);
}

void test_value_returned_non_opt_constructor() {
    ValueReturnedResult<int> res = ValueReturnedResult<int>(
        VALUE_RETURNED_RESULT_CODE,
        VALUE_RETURNED_RESULT_VALUE,
        VALUE_RETURNED_RESULT_MESSAGE
    );
    test_value_returned_result_is_correct(res);
}

void test_value_returned_no_message_constructor() {
    ValueReturnedResult<int> res = ValueReturnedResult<int>(
        VALUE_RETURNED_RESULT_CODE,
        VALUE_RETURNED_RESULT_VALUE
    );
    test_value_returned_result_code(VALUE_RETURNED_RESULT_CODE, res.code());
    TEST_ASSERT_TRUE(is_value_returned_result_value_present(res.value()));
    test_value_returned_result_value(VALUE_RETURNED_RESULT_VALUE, res.value().value());
    TEST_ASSERT_FALSE(is_value_returned_result_message_present(res.message()));
}

void test_value_returned_message_constructor() {
        ValueReturnedResult<int> res = ValueReturnedResult<int>(
        VALUE_RETURNED_RESULT_CODE,
        std::nullopt,
        std::string(VALUE_RETURNED_RESULT_MESSAGE)
    );
    test_value_returned_result_code(VALUE_RETURNED_RESULT_CODE, res.code());
    TEST_ASSERT_TRUE(is_value_returned_result_value_present(res.message()));
    test_value_returned_result_message(VALUE_RETURNED_RESULT_MESSAGE, res.message().value());
    TEST_ASSERT_FALSE(is_value_returned_result_value_present(res.value()));

}

void test_ValueReturnedResultTest(){
    RUN_TEST(test_value_returned_code_constructor);
    RUN_TEST(test_value_returned_full_constructor);
    RUN_TEST(test_value_returned_non_opt_constructor);
    RUN_TEST(test_value_returned_message_constructor);
    RUN_TEST(test_value_returned_no_message_constructor);
}
