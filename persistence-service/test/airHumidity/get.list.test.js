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
const listTests = require('../util/templates/pairTimestampValue/list')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const registerRoute = "/airHumidity/register"
const listRoute = "/airHumidity/list"

test("Retreiving correct Air Humidity list", async () => {
    await listTests.correctList(registerRoute, listRoute)
})

test("Wrong token for Air Humidity list", async () => {
    await listTests.wrongToken(listRoute)
})
