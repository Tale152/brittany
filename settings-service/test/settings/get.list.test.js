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

async function correctSettingsList(body, then){
    await httpTest.get(server, "/settings/list", body, values.correctFarmerToken, 200, then)
}

test("No settings created", async () => {
    await correctSettingsList({ id: values.idEnvironment }, (res) => { expect(res.body.settings.length).toBe(0) })
})

test("No id provided", async () => {
    await httpTest.get(server, "/settings/list", {}, values.correctFarmerToken, 406, (res) => expect(res.body).toHaveProperty("err"))
})

test("Correct listing", async () => {
    await correctCreate({
        idEnvironment: values.idEnvironment,
        expires: new Date(new Date().getTime() + 30000),
        temperature: {
            min: 0,
            max: 7
        }
    })
    await correctCreate({
        idEnvironment: values.idEnvironment,
        expires: new Date(new Date().getTime() + 60000),
        temperature: {
            min: 7,
            max: 42
        }
    })
    await correctSettingsList({ id: values.idEnvironment }, (res) => { 
        expect(res.body.settings.length).toBe(2) 
        expect(res.body.settings[0].data.temperature.max).toBe(42)
    })
})
