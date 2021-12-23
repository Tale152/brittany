const server = require('../../src/server')
const db = require('../util/db')
const httpTest = require('../util/httpTest')
const values = require('../util/values')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

async function temperatureRegister(body){
    await httpTest.post(server, "/temperature/register", body, values.correctAgentToken, 201, (res) => expect(res.body).toHaveProperty("id"))
}

async function temperatureLatest(query, token, code, then){
    await httpTest.get(server, "/temperature/latest", query, token, code, then)
}

test("Retreiving with just one value", async () => {
    const value = 42
    await temperatureRegister(
        {
            id: values.idSettings,
            value: value,
            timestamp: new Date()
        }
    )
    await temperatureLatest(
        {
            id: values.idSettings
        },
        values.correctAgentToken,
        200,
        (res) => expect(res.body.value).toBe(value)
    )
})

test("Retreiving with multiple values", async () => {
    const valueOldest = 42
    const dateOldest = new Date()
    const valueNewest = 7
    const dateNewest = new Date(dateOldest.getTime() + 60000)

    await temperatureRegister(
        {
            id: values.idSettings,
            value: valueOldest,
            timestamp: dateOldest
        }
    )
    await temperatureRegister(
        {
            id: values.idSettings,
            value: valueNewest,
            timestamp: dateNewest
        }
    )
    await temperatureLatest(
        {
            id: values.idSettings
        },
        values.correctAgentToken,
        200,
        (res) => expect(res.body.value).toBe(valueNewest)
    )
})

test("Not existing Settings id", async () => {
    await temperatureLatest(
        {
            id: values.idSettings
        },
        values.correctAgentToken,
        404,
        (res) => {/* does nothing */}
    )
})

test("Wrong token", async () => {
    await temperatureLatest(
        {
            id: values.idSettings
        },
        values.wrongToken,
        401,
        (res) => {/* does nothing */}
    )
})
