//
// Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "OperationHandler.h"
#include "util.h"

OperationHandler::OperationHandler(
    std::string name,
    std::string path,
    OperationType operationType,
    Type outputType
) {
    _name = name;
    _path = path;
    _operationType = operationType;
    _outputType = outputType;
}


OperationHandler::OperationHandler(
    std::string name,
    OperationType operationType,
    Type outputType
) {
    _name = name;
    _path = as_route(name);
    _operationType = operationType;
    _outputType = outputType;
}


std::string OperationHandler::name() {
    return _name;
}

std::string OperationHandler::path() {
    return _path;
}

Type OperationHandler::outputType() {
    return _outputType;
}

OperationType OperationHandler::operationType() {
    return _operationType;
}
