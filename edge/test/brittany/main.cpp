#include <unity.h>
#include "OperationHandlerResultTest.h"
#include "OperationHandlerTest.h"

int main(){
    UNITY_BEGIN();
    test_OperationHandlerResult(); //OperationHandlerResultTest
    test_OperationHandler(); //OperationHandlerTest
    UNITY_END();
}