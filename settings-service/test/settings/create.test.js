const server = require('../../src/server')
const db = require('../util/db')
const values = require('../util/values')
const httpTest = require('../util/httpTest')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const active = true
const expires = new Date(new Date().getTime() + 60000)

const correctBody = {
    idEnvironment: values.idEnvironment,
    active: active,
    expires: expires
}

async function settingsCreateMissingFileds(body){
    await settingsCreate(body, values.correctFarmerToken, 406, (res) => { expect(res.body).toHaveProperty("err") })
}

async function settingsCreate(body, token, code, then){
    await httpTest.post(server, "/settings/create", body, token, code, then)
}

test("Correct Settings creation", async () => {
    await settingsCreate(correctBody, values.correctFarmerToken, 201, (res) => expect(res.body).toHaveProperty("id"))
})

test("Wrong token", async () => {
    await settingsCreate(correctBody, values.wrongToken, 401, (res) => { /* does nothing */})
})

test("Missing body fields", async () => {
    await settingsCreateMissingFileds({
        active: active,
        expires: expires
    })
    await settingsCreateMissingFileds({
        idEnvironment: values.idEnvironment,
        expires: expires
    })
    await settingsCreateMissingFileds({
        idEnvironment: values.idEnvironment,
        active: active,
    })
})
