const supertest = require('supertest')
const jwt = require('jsonwebtoken')

const server = require('../../src/server')
const db = require('../util/db')
const agentTokenSecret = require('../../src/conf').agentTokenSecret

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const token = jwt.sign({}, agentTokenSecret)
const idEnvironment = "61c099edd3c873c6030793b7"
const value = 42
const timestamp = new Date()

const correctBody = {
    id: idEnvironment,
    value: value,
    timestamp: timestamp
}

async function airHumidityRegister(body, token, code, then){
    await supertest(server)
        .post("/airHumidity/register")
        .send(body)
        .set('token', token)
        .set('Accept', 'application/json')
        .expect(code)
        .then((res) => then(res))
}

test("Correct Air Humidity registration", async () => {
    await airHumidityRegister(correctBody, token, 201, (res) => expect(res.body).toHaveProperty("id"))
})

test("Wrong token", async () => {
    await airHumidityRegister(correctBody, jwt.sign({}, "wrong"), 401, (res) => {/* does nothing */})
})

test("Missing id", async () => {
    await airHumidityRegister(
        {
            value: value,
            timestamp: timestamp
        },
        token,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})

test("Missing value", async () => {
    await airHumidityRegister(
        {
            id: idEnvironment,
            timestamp: timestamp
        },
        token,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})

test("Value not numeric", async () => {
    await airHumidityRegister(
        {
            id: idEnvironment,
            value: "not a number",
            timestamp: timestamp
        },
        token,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})

test("Missing timestamp", async () => {
    await airHumidityRegister(
        {
            id: idEnvironment,
            value: value
        },
        token,
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})
