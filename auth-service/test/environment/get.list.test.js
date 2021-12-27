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
    var id
    await correctOrganizationCreate((res) => {token = res.body.token})
    await httpTest.post(server, "/greenhouse/create",{
        name: values.greenhouseName
    }, token, 201, (res) => { id = res.body.id })
    await httpTest.get(server, "/greenhouse/list",{}, token, 200, (res) => { expect(res.body.greenhouses[0]._id).toBe(id) })
})

test("Wrong token", async () => {
    await httpTest.get(server, "/greenhouse/list",{}, values.wrongToken, 401, (res) => { /* does nothing */ })
})
