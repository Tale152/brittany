const server = require('../../src/server')
const db = require('../util/db')
const httpTest = require('../util/httpTest')
const values = require('../util/values')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const value = 42
const timestamp = new Date()

const correctBody = {
    id: values.idSettings,
    value: value,
    timestamp: timestamp
}

async function airHumidityRegister(body, token, code, then){
    await httpTest.post(server, "/airHumidity/register", body, token, code, then)
}

test("Correct Air Humidity registration", async () => {
    await airHumidityRegister(correctBody, values.correctAgentToken, 201, (res) => expect(res.body).toHaveProperty("id"))
})

test("Wrong token", async () => {
    await airHumidityRegister(correctBody, values.wrongToken, 401, (res) => {/* does nothing */})
})

test("Missing id", async () => {
    await airHumidityRegister(
        {
            value: value,
            timestamp: timestamp
        },
        values.correctAgentToken,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})

test("Missing value", async () => {
    await airHumidityRegister(
        {
            id: values.idSettings,
            timestamp: timestamp
        },
        values.correctAgentToken,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})

test("Value not numeric", async () => {
    await airHumidityRegister(
        {
            id: values.idSettings,
            value: "not a number",
            timestamp: timestamp
        },
        values.correctAgentToken,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})

test("Missing timestamp", async () => {
    await airHumidityRegister(
        {
            id: values.idSettings,
            value: value
        },
        values.correctAgentToken,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})
