#ifndef BRITTANY_UTIL_H
#define BRITTANY_UTIL_H

#include "hw/ComponentHw.h"
#include <list>
#include <string>
#include <optional>

enum class ContentResult {
    Ok,
    ResourceNotFound,
    OperationFailed,
    BadRequest
};

/**
 * @brief Return a string description to insert in the content result.
 * 
 * @param content the value of ContentResult to convert to string.
 * @return std::string the converted string.
 */
inline std::string phrase(ContentResult content) {
    switch (content) {
    case ContentResult::Ok:
        return "Ok.";
    case ContentResult::ResourceNotFound:
        return "The requested resource does not exist.";
    case ContentResult::OperationFailed:
        return "Operation failed.";
    case ContentResult::BadRequest:
        return "Bad Request";
    default:
        return "";
        break;
    }
}

/**
 * @brief Return the same string with a slash in front.
 * Used to avoid repetitions of name and paths in Handlers.
 * 
 * @param string the input string.
 * @return std::string the string as route (/string)
 */
inline std::string as_route(std::string string) {
    return "/" + string;
}


/**
 * @tparam T The class of elements contained in the list.
 */
template <class T>

/**
 * @brief Return the T with the chosen id if present.
 * 
 * @param list the list of T.
 * @param id the id of the T to find.
 * @return std::optional<T> nullopt if the id is not found, the value otherwise.
 */
inline std::optional<T> find_by_id(std::list<T> list, std::string id) {
    for(T c : list) {
        if(c->id() == id) {
            return std::optional(c);
        }
    }
    return std::nullopt;
}

#endif //BRITTANY_UTIL_H