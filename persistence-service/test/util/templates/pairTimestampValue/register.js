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

const server = require('../../../../src/server')
const httpTest = require('../../httpTest')
const values = require('../../values')
const correctRegister = require('./correctRegister')

const value = 42
const timestamp = new Date()

const correctBody = {
    value: value,
    timestamp: timestamp
}

module.exports.correctRegister = async function(route){
    await correctRegister.exec(route, correctBody)
}

module.exports.wrongToken = async function(route){
    await httpTest.post(
        server,
        route,
        correctBody,
        values.wrongToken,
        401,
        (res) => {/* does nothing */}
    )
}

module.exports.missingBodyFields = async function(route){
    await httpTest.post(
        server,
        route,
        {
            timestamp: timestamp
        },
        values.correctAgentToken,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
    await httpTest.post(
        server,
        route,
        {
            value: value
        },
        values.correctAgentToken,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
}

module.exports.bodyValueNotNumeric = async function(route){
    await httpTest.post(
        server,
        route,
        {
            value: "not a number",
            timestamp: timestamp
        },
        values.correctAgentToken,
        406,
        (res) => {/* does nothing */}
    )
}
