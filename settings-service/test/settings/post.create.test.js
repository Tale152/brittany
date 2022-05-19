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

const server = require('../../src/server')
const db = require('../util/db')
const values = require('../util/values')
const httpTest = require('../util/httpTest')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const expires = new Date(new Date().getTime() + 60000)

const correctBody = {
    idEnvironment: values.idEnvironment,
    expires: expires
}

async function settingsCreate406(body){
    await settingsCreate(body, values.correctFarmerToken, 406, (res) => { expect(res.body).toHaveProperty("err") })
}

async function settingsCreate(body, token, code, then){
    await httpTest.post(server, "/settings/create", body, token, code, then)
}

test("Correct Settings creation", async () => {
    await settingsCreate(correctBody, values.correctFarmerToken, 201, (res) => expect(res.body).toHaveProperty("id"))
})

test("Wrong token", async () => {
    await settingsCreate(correctBody, values.wrongToken, 401, (res) => { /* does nothing */})
})

test("Missing body fields", async () => {
    await settingsCreate406({
        expires: expires
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        temperature: {
            min: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        temperature: {
            max: 1,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        airHumidity: {
            min: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        airHumidity: {
            max: 1,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        light: {
            fromM: 30,
            toH: 5,
            toM: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        light: {
            fromH: 18,
            toH: 5,
            toM: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        light: {
            fromH: 18,
            fromM: 30,
            toM: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        light: {
            fromH: 18,
            fromM: 30,
            toH: 5,
        }
    })
})

test("Wrong params type", async () => {
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        temperature: {
            min: "NaN",
            max: 1
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        temperature: {
            min: 0,
            max: "NaN",
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        airHumidity: {
            min: "NaN",
            max: 1,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        airHumidity: {
            min: 0,
            max: "NaN",
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        light: {
            fromH: "NaN",
            fromM: 30,
            toH: 5,
            toM: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        light: {
            fromH: 18,
            fromM: "NaN",
            toH: 5,
            toM: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        light: {
            fromH: 18,
            fromM: 30,
            toH: "NaN",
            toM: 0,
        }
    })
    await settingsCreate406({
        idEnvironment: values.idEnvironment,
        idEnvironment: values.idEnvironment,
        light: {
            fromH: 18,
            fromM: 30,
            toH: 5,
            toM: "NaN",
        }
    })
})
