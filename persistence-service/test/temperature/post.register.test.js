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

const db = require('../util/db')
const registerTests = require('../util/templates/pairTimestampValue/register')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const route = "/temperature/register"

test("Correct Temperature registration", async () => {
    await registerTests.correctRegister(route)
})

test("Wrong token on Temperature registration", async () => {
    await registerTests.wrongToken(route)
})

test("Missing body fields on Temperature registration", async () => {
    await registerTests.missingBodyFields(route)
})

test("Body value not numeric on Temperature registration", async () => {
    await registerTests.bodyValueNotNumeric(route)
})
