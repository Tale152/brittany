#ifndef BRITTANY_MOCK_SERIAL_ARGS_OPERATION_HANDLER_H
#define BRITTANY_MOCK_SERIAL_ARGS_OPERATION_HANDLER_H

#include <Arduino.h>
#include <string>
#include "operation-handler/MockArgsOperationHandler.h"

/**
 * @brief Implementation of MockArgsOperationHandler specific for an Arduino enviroment.
 * 
 */
class MockSerialArgsOperationHandler: public MockArgsOperationHandler {

public:

    MockSerialArgsOperationHandler(std::string path) : MockArgsOperationHandler(path) {
        // does nothing
    };

private:

    void stdOutStrategy(std::string content) {
        Serial.println(content.c_str());
    }

};

#endif //BRITTANY_MOCK_SERIAL_ARGS_OPERATION_HANDLER_H