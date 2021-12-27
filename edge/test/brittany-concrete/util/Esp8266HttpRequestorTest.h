#include <unity.h>
#include "util/Esp8266HttpRequestor.h"
#include "HttpStatusCodes_C++.h"
#include "json_util.h"

Esp8266HttpRequestor requestor = Esp8266HttpRequestor();

void test_http_requestor_get() {
    std::tuple<int, std::string> result = requestor.makeHttpGetRequest(
        "http://jsonplaceholder.typicode.com/todos/1",
        "text/plain"
    );
    TEST_ASSERT_EQUAL(HttpStatus::OK, std::get<0>(result));
    std::optional<Json::Value> response_content = to_json(std::get<1>(result));
    TEST_ASSERT_TRUE(response_content.has_value());
    Json::Value response_body = response_content.value();
    TEST_ASSERT_EQUAL(1, response_body["userId"].asInt());
    TEST_ASSERT_EQUAL(1, response_body["id"].asInt());
    TEST_ASSERT_EQUAL_STRING("delectus aut autem", response_body["title"].asCString());
    TEST_ASSERT_FALSE(response_body["completed"].asBool());
}

void test_http_requestor_post() {
    Json::Value request_body;
    request_body["title"] = "foo";
    request_body["body"] = "bar";
    request_body["userId"] = 1;
    std::tuple<int, std::string> result = requestor.makeHttpPostRequest(
        "http://jsonplaceholder.typicode.com/posts",
        "application/json",
        stringify(request_body)
    );
    TEST_ASSERT_EQUAL(HttpStatus::Created, std::get<0>(result));
    std::optional<Json::Value> response_content = to_json(std::get<1>(result));
    TEST_ASSERT_TRUE(response_content.has_value());
    Json::Value response_body = response_content.value();
    TEST_ASSERT_TRUE(response_body.isMember("id"));
    TEST_ASSERT_EQUAL_STRING("foo", response_body["title"].asCString());
    TEST_ASSERT_EQUAL_STRING("bar", response_body["body"].asCString());
    TEST_ASSERT_EQUAL(1, response_body["userId"].asInt());
}

void test_Esp8266HttpRequestor() {
    RUN_TEST(test_http_requestor_get);
    RUN_TEST(test_http_requestor_post);
}
