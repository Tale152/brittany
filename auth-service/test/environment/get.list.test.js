const server = require('../../src/server')
const httpTest = require('../util/httpTest')
const db = require('../util/db')
const values = require('../util/values')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

async function correctOrganizationCreate(then){
    await httpTest.post(server, "/organization/create", values.correctOrganizationBody, "", 201, (res) => then(res))
}

test("Correct list", async () => {
    var token
    var greenhouseId
    await correctOrganizationCreate((res) => {token = res.body.token})
    await httpTest.post(server, "/greenhouse/create",{
        name: values.greenhouseName
    }, token, 201, (res) => { greenhouseId = res.body.id })
    await httpTest.post(server, "/environment/create",{
        greenhouseId: greenhouseId,
        name: values.environmentName,
        password: values.environmentPassword
    }, token, 201, (res) => { /* does nothing */ })
    await httpTest.get(server, "/environment/list",{
        id: greenhouseId
    }, token, 200, (res) => { expect(res.body.greenhouses[0].name).toBe(values.environmentName) })
})

test("Wrong token", async () => {
    await httpTest.get(server, "/environment/list",{}, values.wrongToken, 401, (res) => { /* does nothing */ })
})
