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

test("Correct registration", async () => {
    var token
    await correctOrganizationCreate((res) => {token = res.body.token})
    await httpTest.post(server, "/farmer/register",{
        name: values.name,
        surname: values.surname,
        birthdate: values.birthdate,
        mail: "another." + values.mail,
        password: values.password
    }, token, 201, (res) => { /* does nothing */ })
})

test("Duplicate mail", async () => {
    var token
    await correctOrganizationCreate((res) => {token = res.body.token})
    await httpTest.post(server, "/farmer/register",{
        name: values.name,
        surname: values.surname,
        birthdate: values.birthdate,
        mail: values.mail,
        password: values.password
    }, token, 406, (res) => { /* does nothing */ })
})
