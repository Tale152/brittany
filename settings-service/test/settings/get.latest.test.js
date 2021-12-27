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

async function correctSetLatestActiveState(body){
    await httpTest.post(server, "/settings/latestActiveState", body, values.correctFarmerToken, 201, (res) => expect(res.body).toHaveProperty("active"))
}

async function latest(body, token, code, then){
    await httpTest.get(server, "/settings/latest", body, token, code, then)
}

test("Correct latest get", async () => {
    await correctCreate({
        idEnvironment: values.idEnvironment,
        expires: new Date(new Date().getTime() + 10000)
    })
    await latest({}, values.correctAgentToken, 200, (res) => expect(res.body).toHaveProperty("expires"))
})

test("Wrong token", async () => {
    await latest({}, values.wrongToken, 401, (res) => { /* does nothing */})
})

test("Latest is not active", async () => {
    await correctCreate({
        idEnvironment: values.idEnvironment,
        expires: new Date(new Date().getTime() + 10000)
    })
    await correctSetLatestActiveState({
        idEnvironment: values.idEnvironment,
        active: false
    })
    await latest({}, values.correctAgentToken, 404, (res) => expect(res.body).toHaveProperty("err"))
})

function wait(ms) {
    var start = Date.now(),
        now = start;
    while (now - start < ms) {
      now = Date.now();
    }
}

test("Latest is expired", async () => {
    await correctCreate({
        idEnvironment: values.idEnvironment,
        expires: new Date(new Date().getTime() + 1500)
    })
    wait(1600)
    await latest({}, values.correctAgentToken, 404, (res) => expect(res.body).toHaveProperty("err"))
})

test("No settings present", async () => {
    await latest({}, values.correctAgentToken, 404, (res) => expect(res.body).toHaveProperty("err"))
})
