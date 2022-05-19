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

#include <unity.h>
#include "operation-handler/types/Type.h"

void is_type_string_as_expected(std::string expected, std::string actual) {
    TEST_ASSERT_EQUAL_STRING(expected.c_str(), actual.c_str());
}

void test_type_to_string() {
    is_type_string_as_expected("object", type_to_string(Type::OBJECT));
    is_type_string_as_expected("array", type_to_string(Type::ARRAY));
    is_type_string_as_expected("string", type_to_string(Type::STRING));
    is_type_string_as_expected("number", type_to_string(Type::NUMBER));
    is_type_string_as_expected("integer", type_to_string(Type::INTEGER));
    is_type_string_as_expected("boolean", type_to_string(Type::BOOLEAN));
    is_type_string_as_expected("null", type_to_string(Type::NULL_TYPE));
    is_type_string_as_expected("null", type_to_string(Type(198)));
}

void test_Type(){
    RUN_TEST(test_type_to_string);
}
 