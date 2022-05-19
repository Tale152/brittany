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

async function organizationCreate(body, code, then){
    await httpTest.post(server, "/organization/create", body, "", code, then)
}

test("Correct Organization creation", async () => {
    await organizationCreate(values.correctOrganizationBody, 201, (res) => expect(res.body).toHaveProperty("token"))
})

test("Block Organization creation on duplicate Organization name", async () => {
    await organizationCreate(values.correctOrganizationBody, 201, (res) => expect(res.body).toHaveProperty("token"))
    await organizationCreate(
        {
            organizationName: values.organizationName,
            name: values.name,
            surname: values.surname,
            mail: "different." + values.mail,
            birthdate: values.birthdate,
            password: values.password
        },
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})

test("Block Organization creation on duplicate Farmer mail", async () => {
    await organizationCreate(values.correctOrganizationBody, 201, (res) => expect(res.body).toHaveProperty("token"))
    await organizationCreate(
        {
            organizationName: "different " + values.organizationName,
            name: values.name,
            surname: values.surname,
            mail: values.mail,
            birthdate: values.birthdate,
            password: values.password
        },
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})
