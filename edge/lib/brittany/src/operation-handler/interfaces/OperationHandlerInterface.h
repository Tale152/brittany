#ifndef BRITTANY_OPERATION_HANDLER_INTERFACE_H
#define BRITTANY_OPERATION_HANDLER_INTERFACE_H

#include <list>
#include <string>
#include <json/json.h>
#include "operation-handler/OperationHandler.h"

/**
 * @brief General Operation handler interface that execute an operation and return an
 *        OperationHandlerResult based on if it succeded or not.
 * 
 */
class OperationHandlerInterface : public OperationHandler {

public:

    OperationHandlerInterface(std::string path);

    OperationHandlerResult handle(Json::Value args);

private:

    /**
     * @brief Second template method used to execute an operation on args.
     * 
     * @param args the arguments used by the operation.
     * @return true if the operation succeed.
     * @return false if the operation fails.
     */
    virtual bool operation(Json::Value args) = 0;

};

#endif //BRITTANY_OPERATION_HANDLER_INTERFACE_H
