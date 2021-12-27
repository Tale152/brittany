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

test("Correct creation", async () => {
    var token
    await correctOrganizationCreate((res) => {token = res.body.token})
    await httpTest.post(server, "/greenhouse/create",{
        name: values.greenhouseName
    }, token, 201, (res) => { /* does nothing */ })
    await httpTest.post(server, "/greenhouse/create",{
        name: values.greenhouseName + "2"
    }, token, 201, (res) => { /* does nothing */ })
})

test("Duplicate Greenhouse name", async () => {
    var token
    await correctOrganizationCreate((res) => {token = res.body.token})
    await httpTest.post(server, "/farmer/register",{
        name: values.greenhouseName
    }, token, 406, (res) => { /* does nothing */ })
})
