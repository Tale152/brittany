#ifndef BRITTANY_MOCK_EDGE_H
#define BRITTANY_MOCK_EDGE_H

#include <string>
#include <list>
#include <json/json.h>
#include "operation-handler/OperationHandler.h"
#include "edge/Edge.h"
#include "operation-handler/MockOperationHandler.h"
#include "thing-descriptor/ThingDescriptor.h"

#define MOCK_EDGE_OPERATION_HANDLER_PATH "/value"

class MockEdge : public Edge{

public:

    MockEdge() : Edge(std::list<OperationHandler*>({handler})) { };
    
    ~MockEdge() {
        delete handler;
    }

private:

    OperationHandler* handler = new MockOperationHandler(MOCK_EDGE_OPERATION_HANDLER_PATH);

};

#endif //BRITTANY_MOCK_EDGE_H