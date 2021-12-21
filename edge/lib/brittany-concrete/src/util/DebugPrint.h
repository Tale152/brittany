#ifndef BRITTANY_CONCRETE_UTIL_H
#define BRITTANY_CONCRETE_UTIL_H

#include <string>
#include <Arduino.h>

/**
 * @brief Class used fro debug print purpose.
 * 
 */
class DebugPrint {

public:

    /**
     * @brief Construct a new Debug Print object.
     * 
     * @param debug specify if debug is enabled.
     */
    DebugPrint(bool debug) {
        _debug = debug;
    }

    /**
     * @brief Print on stdout with newline only if debug is enabled.
     * 
     * @param str 
     */
    void println(std::string str) {
        if(_debug) {
            Serial.println(str.c_str());
        }
    }

private:

    bool _debug;

};

#endif //BRITTANY_CONCRETE_UTIL_H