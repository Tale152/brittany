#ifndef BRITTANY_JSON_UTIL_H
#define BRITTANY_JSON_UTIL_H

#include <json/json.h>
#include <string>
#include <optional>

/**
 * @brief Map the Json::Value to the corresponding std::string.
 * 
 * @param json the Json::Value.
 * @return std::string the corresponding std::string.
 */
inline std::string stringify(Json::Value json) {
    Json::StreamWriterBuilder builder;
    builder["indentation"] = "";
    return Json::writeString(builder, json);
}

/**
 * @brief Parse a string and return the corresponding Json::Value.
 * 
 * @param string the string to parse.
 * @return std::optional<Json::Value> the value if the parsing succeeded, empty otherwise. 
 */
std::optional<Json::Value> to_json(std::string string) {
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    Json::Value json;
    std::string errors;
    bool success = reader->parse(
        string.c_str(),
        string.c_str() + string.size(),
        &json,
        &errors
    );
    delete reader;
    if (!success) {
        return std::nullopt;
    }
    return std::optional(json);
}

#endif //BRITTANY_JSON_UTIL_H