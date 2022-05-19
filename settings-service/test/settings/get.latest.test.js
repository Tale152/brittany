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

async function correctSetLatestActiveState(body){
    await httpTest.post(server, "/settings/latestActiveState", body, values.correctFarmerToken, 201, (res) => expect(res.body).toHaveProperty("active"))
}

async function latest(body, token, code, then){
    await httpTest.get(server, "/settings/latest", body, token, code, then)
}

test("Correct latest get", async () => {
    await correctCreate({
        idEnvironment: values.idEnvironment,
        expires: new Date(new Date().getTime() + 10000)
    })
    await latest({}, values.correctAgentToken, 200, (res) => expect(res.body).toHaveProperty("expires"))
})

test("Wrong token", async () => {
    await latest({}, values.wrongToken, 401, (res) => { /* does nothing */})
})

test("Latest is not active", async () => {
    await correctCreate({
        idEnvironment: values.idEnvironment,
        expires: new Date(new Date().getTime() + 10000)
    })
    await correctSetLatestActiveState({
        idEnvironment: values.idEnvironment,
        active: false
    })
    await latest({}, values.correctAgentToken, 404, (res) => expect(res.body).toHaveProperty("err"))
})

function wait(ms) {
    var start = Date.now(),
        now = start;
    while (now - start < ms) {
      now = Date.now();
    }
}

test("Latest is expired", async () => {
    await correctCreate({
        idEnvironment: values.idEnvironment,
        expires: new Date(new Date().getTime() + 1500)
    })
    wait(1600)
    await latest({}, values.correctAgentToken, 404, (res) => expect(res.body).toHaveProperty("err"))
})

test("No settings present", async () => {
    await latest({}, values.correctAgentToken, 404, (res) => expect(res.body).toHaveProperty("err"))
})
