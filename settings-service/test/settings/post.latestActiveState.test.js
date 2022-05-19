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

async function correctCreate(body){
    await httpTest.post(server, "/settings/create", body, values.correctFarmerToken, 201, (res) => expect(res.body).toHaveProperty("id"))
}

async function correctLatestActiveState(body){
    await httpTest.post(server, "/settings/latestActiveState", body, values.correctFarmerToken, 201, (res) => expect(res.body.active).toBe(body.active))
}

test("Correct active state setting", async () => {
    await correctCreate({
        idEnvironment: values.idEnvironment,
        expires: new Date(new Date().getTime() + 10000)
    })
    await correctLatestActiveState({
        idEnvironment: values.idEnvironment,
        active: false
    })
})

test("No settings to set state", async () => {
    await httpTest.post(server, "/settings/latestActiveState", {
        idEnvironment: values.idEnvironment,
        active: false
    }, values.correctFarmerToken, 404, (res) => expect(res.body).toHaveProperty("err"))
})

test("Wrong token", async () => {
    await httpTest.post(server, "/settings/latestActiveState", {
        idEnvironment: values.idEnvironment,
        active: false
    }, values.wrongToken, 401, (res) => { /* does nothing */ })
})

test("Missing body params", async () => {
    await httpTest.post(server, "/settings/latestActiveState", {
        active: false
    }, values.correctFarmerToken, 406, (res) => expect(res.body).toHaveProperty("err"))
    await httpTest.post(server, "/settings/latestActiveState", {
        idEnvironment: values.idEnvironment
    }, values.correctFarmerToken, 406, (res) => expect(res.body).toHaveProperty("err"))
})
