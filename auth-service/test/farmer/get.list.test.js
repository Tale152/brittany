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
    await correctOrganizationCreate((res) => {token = res.body.token})
    await httpTest.get(server, "/farmer/list",{}, token, 200, (res) => { expect(res.body.farmers.length).toBe(1) })
})

test("Wrong token", async () => {
    await httpTest.get(server, "/farmer/list",{}, values.wrongToken, 401, (res) => { /* does nothing */ })
})
