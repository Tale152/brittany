#ifndef BRITTANY_OPERATION_HANDLER_H
#define BRITTANY_OPERATION_HANDLER_H

#include <string>
#include <json/json.h>
#include "OperationHandlerResult.h"

/**
 * @brief Class that represents an operation that uses some arguments for a computation and
 *        returns an OperationHandlerResult.
 *        The behaviour of this class is similar to an handler in a REST architecture.
 */
class OperationHandler {

public:

    /**
     * @brief Construct a new Operation Handler object.
     * 
     * @param name The name of the OperationHandler
     * @param path The path of the OperationHandler.
     */
    OperationHandler(std::string name, std::string path);


    /**
     * @brief Return the name of the OperationHandler.
     * 
     * @return std::string the name of the operation.
     */
    std::string name();

    /**
     * @brief Return the path of the OperationHandler.
     * 
     * @return std::string the path(route) of the operation.
     */
    std::string path();

    /**
     * @brief execute the OperationHandler. This method wiill often act as a template method.
     * 
     * @param args Arguments of the OperationHandler used for computation.
     * @return OperationHandlerResult The result of the computation.
     */
    virtual OperationHandlerResult handle(Json::Value args) = 0;

private:

    std::string _name;
    std::string _path;

};

#endif //BRITTANY_OPERATION_HANDLER_H