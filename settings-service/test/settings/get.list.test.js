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

async function correctSettingsList(body, then){
    await httpTest.get(server, "/settings/list", body, values.correctFarmerToken, 200, then)
}

test("No settings created", async () => {
    await correctSettingsList({ id: values.idEnvironment }, (res) => { expect(res.body.settings.length).toBe(0) })
})

test("No id provided", async () => {
    await httpTest.get(server, "/settings/list", {}, values.correctFarmerToken, 406, (res) => expect(res.body).toHaveProperty("err"))
})

test("Correct listing", async () => {
    await correctCreate({
        idEnvironment: values.idEnvironment,
        expires: new Date(new Date().getTime() + 30000),
        temperature: {
            min: 0,
            max: 7
        }
    })
    await correctCreate({
        idEnvironment: values.idEnvironment,
        expires: new Date(new Date().getTime() + 60000),
        temperature: {
            min: 7,
            max: 42
        }
    })
    await correctSettingsList({ id: values.idEnvironment }, (res) => { 
        expect(res.body.settings.length).toBe(2) 
        expect(res.body.settings[0].data.temperature.max).toBe(42)
    })
})
