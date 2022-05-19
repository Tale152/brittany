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

module.exports.latestOneValue = async function(registerRoute, retreiveRoute){
    const value = 42
    await correctRegister.exec(
        registerRoute, 
        {
            value: value,
            timestamp: new Date()
        }
    )
    await httpTest.get(
        server,
        retreiveRoute,
        {},
        values.correctAgentToken,
        200,
        (res) => expect(res.body.value).toBe(value)
    )
}

module.exports.latestMultipleValues = async function(registerRoute, retreiveRoute){
    const valueOldest = 42
    const dateOldest = new Date()
    const valueNewest = 7
    const dateNewest = new Date(dateOldest.getTime() + 60000)

    await correctRegister.exec(
        registerRoute,
        {
            value: valueOldest,
            timestamp: dateOldest
        }
    )

    await correctRegister.exec(
        registerRoute,
        {
            value: valueNewest,
            timestamp: dateNewest
        }
    )

    await httpTest.get(
        server,
        retreiveRoute,
        {},
        values.correctAgentToken,
        200,
        (res) => expect(res.body.value).toBe(valueNewest)
    )
}

module.exports.notExistingId = async function(retreiveRoute){
    await httpTest.get(
        server,
        retreiveRoute,
        {},
        values.correctAgentToken,
        404,
        (res) => {/* does nothing */}
    )
}

module.exports.wrongToken = async function(retreiveRoute){
    await httpTest.get(
        server,
        retreiveRoute,
        {},
        values.wrongToken,
        401,
        (res) => {/* does nothing */}
    )
}
