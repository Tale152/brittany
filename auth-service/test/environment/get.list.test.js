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
const httpTest = require('../util/httpTest')
const db = require('../util/db')
const values = require('../util/values')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

async function correctOrganizationCreate(then){
    await httpTest.post(server, "/organization/create", values.correctOrganizationBody, "", 201, (res) => then(res))
}

test("Correct list", async () => {
    var token
    var greenhouseId
    await correctOrganizationCreate((res) => {token = res.body.token})
    await httpTest.post(server, "/greenhouse/create",{
        name: values.greenhouseName
    }, token, 201, (res) => { greenhouseId = res.body.id })
    await httpTest.post(server, "/environment/create",{
        greenhouseId: greenhouseId,
        name: values.environmentName,
        password: values.environmentPassword
    }, token, 201, (res) => { /* does nothing */ })
    await httpTest.get(server, "/environment/list",{
        id: greenhouseId
    }, token, 200, (res) => { expect(res.body.environments[0].name).toBe(values.environmentName) })
})

test("Wrong token", async () => {
    await httpTest.get(server, "/environment/list",{}, values.wrongToken, 401, (res) => { /* does nothing */ })
})
