const jwt = require('jsonwebtoken')

const server = require('../../src/server')
const db = require('../util/db')
const httpTest = require('../util/httpTest')
const agentTokenSecret = require('../../src/conf').agentTokenSecret

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const token = jwt.sign({}, agentTokenSecret)
const idSettings = "61c099edd3c873c6030793b7"

async function temperatureRegister(body){
    await httpTest.post(server, "/temperature/register", body, token, 201, (res) => expect(res.body).toHaveProperty("id"))
}

async function temperatureLatest(query, token, code, then){
    await httpTest.get(server, "/temperature/latest", query, token, code, then)
}

test("Retreiving with just one value", async () => {
    const value = 42
    await temperatureRegister(
        {
            id: idSettings,
            value: value,
            timestamp: new Date()
        }
    )
    await temperatureLatest(
        {
            id: idSettings
        },
        token,
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
            id: idSettings,
            value: valueOldest,
            timestamp: dateOldest
        }
    )
    await temperatureRegister(
        {
            id: idSettings,
            value: valueNewest,
            timestamp: dateNewest
        }
    )
    await temperatureLatest(
        {
            id: idSettings
        },
        token,
        200,
        (res) => expect(res.body.value).toBe(valueNewest)
    )
})

test("Not existing Settings id", async () => {
    await temperatureLatest(
        {
            id: idSettings
        },
        token,
        404,
        (res) => {/* does nothing */}
    )
})

test("Wrong token", async () => {
    await temperatureLatest(
        {
            id: idSettings
        },
        jwt.sign({}, "wrong"),
        401,
        (res) => {/* does nothing */}
    )
})
