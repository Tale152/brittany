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

#ifndef BRITTANY_JSON_UTIL_H
#define BRITTANY_JSON_UTIL_H

#include <json/json.h>
#include <string>
#include <optional>

/**
 * @brief Get the body of the json object. The body of the post request is always in the plain key.
 * 
 * @param json the original json object.
 * @return Json::Value the object contained in the "plain" key if present, a null Json::Value otherwise.
 */
inline std::optional<Json::Value> body(Json::Value json) {
    if(json.isMember("plain")) {
        return std::optional<Json::Value>(json["plain"]);
    }
    return std::nullopt;
}

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