const supertest = require('supertest')
const jwt = require('jsonwebtoken')

const server = require('../../src/server')
const db = require('../util/db')
const farmerTokenSecret = require('../../src/conf').farmerTokenSecret

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const token = jwt.sign({}, farmerTokenSecret)
const idEnvironment = "61c099edd3c873c6030793b7"
const active = true
const expires = new Date(new Date().getTime() + 60000)

const correctBody = {
    idEnvironment: idEnvironment,
    active: active,
    expires: expires
}

async function settingsCreate(body, code, then){
    await supertest(server)
        .post("/settings/create")
        .send(body)
        .set('token', token)
        .set('Accept', 'application/json')
        .expect('Content-Type', /json/)
        .expect(code)
        .then((res) => then(res))
}

test("Correct Settings creation", async () => {
    await settingsCreate(correctBody, 201, (res) => expect(res.body).toHaveProperty("id"))
})
