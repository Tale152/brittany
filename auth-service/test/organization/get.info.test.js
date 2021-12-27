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

test("Correct info", async () => {
    var token
    await correctOrganizationCreate((res) => {token = res.body.token})
    await httpTest.get(server, "/organization/info",{}, token, 200, (res) => { expect(res.body.name).toBe(values.organizationName) })
})

test("Wrong token", async () => {
    await httpTest.get(server, "/organization/info",{}, values.wrongToken, 401, (res) => { /* does nothing */ })
})
