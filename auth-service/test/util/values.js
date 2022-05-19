/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
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

const jwt = require('jsonwebtoken')

const environmentName = "Test env"
const environmentPassword = "envpsw"
const greenhouseName = "Brittany"
const organizationName = "TestOrganization"
const name = "Peter"
const surname = "Parker"
const mail = "peter.parker@test.com"
const birthdate = "1962-06-05"
const password = "psw"
const correctOrganizationBody = {
    organizationName: organizationName,
    name: name,
    surname: surname,
    mail: mail,
    birthdate: birthdate,
    password: password
}

module.exports = {
    environmentName: environmentName,
    environmentPassword: environmentPassword,
    greenhouseName: greenhouseName,
    organizationName: organizationName,
    name: name,
    surname: surname,
    mail: mail,
    birthdate: birthdate,
    password: password,
    correctOrganizationBody: correctOrganizationBody,
    correctAgentToken: jwt.sign({}, require('../../src/conf').agentTokenSecret),
    correctFarmerToken: jwt.sign({}, require('../../src/conf').farmerTokenSecret),
    wrongToken: jwt.sign({}, "wrong")
}
