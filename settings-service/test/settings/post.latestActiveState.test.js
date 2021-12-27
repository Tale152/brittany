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

async function correctLatestActiveState(body){
    await httpTest.post(server, "/settings/latestActiveState", body, values.correctFarmerToken, 201, (res) => expect(res.body.active).toBe(body.active))
}

test("Correct active state setting", async () => {
    await correctCreate({
        idEnvironment: values.idEnvironment,
        expires: new Date(new Date().getTime() + 10000)
    })
    await correctLatestActiveState({
        idEnvironment: values.idEnvironment,
        active: false
    })
})

test("No settings to set state", async () => {
    await httpTest.post(server, "/settings/latestActiveState", {
        idEnvironment: values.idEnvironment,
        active: false
    }, values.correctFarmerToken, 404, (res) => expect(res.body).toHaveProperty("err"))
})

test("Wrong token", async () => {
    await httpTest.post(server, "/settings/latestActiveState", {
        idEnvironment: values.idEnvironment,
        active: false
    }, values.wrongToken, 401, (res) => { /* does nothing */ })
})

test("Missing body params", async () => {
    await httpTest.post(server, "/settings/latestActiveState", {
        active: false
    }, values.correctFarmerToken, 406, (res) => expect(res.body).toHaveProperty("err"))
    await httpTest.post(server, "/settings/latestActiveState", {
        idEnvironment: values.idEnvironment
    }, values.correctFarmerToken, 406, (res) => expect(res.body).toHaveProperty("err"))
})
