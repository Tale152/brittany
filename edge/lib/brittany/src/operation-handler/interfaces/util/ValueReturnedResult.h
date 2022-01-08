#ifndef BRITTANY_VALUE_RETURNED_RESULT_H
#define BRITTANY_VALUE_RETURNED_RESULT_H

#include <optional>
#include <string>

template <typename T>

/**
 * @brief Class wrapping content returned by a ValueReturnedOperationHandler.
 */
class ValueReturnedResult {

public:

    /**
     * @brief Construct a new Value Returned Result object.
     * 
     * @param code the code.
     * @param opt_value the optional value.
     * @param opt_string the optional message.
     */
    ValueReturnedResult(int code, std::optional<T> opt_value,  std::optional<std::string> opt_msg) {
        _code = code;
        _value = opt_value;
        _message = opt_msg;
    }

    /**
     * @brief Construct a new Value Returned Result object.
     * 
     * @param code the code.
     * @param value the value.
     * @param message the message.
     */
    ValueReturnedResult(int code, T value, std::string message)
        : ValueReturnedResult(code, std::optional<T>(value), std::optional<std::string>(message)) { }

    /**
     * @brief Construct a new Value Returned Result object. The message is empty.
     * 
     * @param code the code.
     * @param value the value.
     */
    ValueReturnedResult(int code, T value)
        : ValueReturnedResult(code, std::optional<T>(value), std::nullopt){ }

    /**
     * @brief Construct a new Value Returned Result object. The value and the message are empty.
     * 
     * @param code the code.
     */
    ValueReturnedResult(int code)
        : ValueReturnedResult(code, std::nullopt, std::nullopt) { }

    
    /**
     * @brief Return the code of the ValueReturnedResult.
     * 
     * @return int a code that describe the ValueResturnResult. HTTP errors are used here.
     */
    int code() {
        return _code;
    }

    /**
     * @brief Return the value of the ValueReturnedResult.
     * 
     * @return std::optional<T> the value if present, empty otherwise.
     */
    std::optional<T> value() {
        return _value;
    }

    /**
     * @brief Return the value of the ValueReturnedResult.
     * 
     * @return std::optional<std::string> the additional message if present, empty otherwise.
     */
    std::optional<std::string> message() {
        return _message;
    }

private:

    int _code;
    std::optional<T> _value;
    std::optional<std::string> _message;

};

#endif //BRITTANY_VALUE_RETURNED_RESULT_H
