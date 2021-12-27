const server = require('../../src/server')
const httpTest = require('../util/httpTest')
const db = require('../util/db')
const values = require('../util/values')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

async function correctOrganizationCreate(){
    await httpTest.post(server, "/organization/create", values.correctOrganizationBody, "", 201, (res) => { /* does nothing */ })
}

test("Correct login", async () => {
    await correctOrganizationCreate()
    await httpTest.get(server, "/farmer/login",{
        mail: values.mail,
        password: values.password
    }, "", 200, (res) => { /* does nothing */ })
})

test("Wrong credentials", async () => {
    await correctOrganizationCreate()
    await httpTest.get(server, "/farmer/login",{
        mail: "another." + values.mail,
        password: "another" + values.password
    }, "", 401, (res) => expect(res.body).toHaveProperty("err"))
    await httpTest.get(server, "/farmer/login",{
        mail: values.mail,
        password: "another" + values.password
    }, "", 401, (res) => expect(res.body).toHaveProperty("err"))
    await httpTest.get(server, "/farmer/login",{
        mail: "another." + values.mail,
        password: values.password
    }, "", 401, (res) => expect(res.body).toHaveProperty("err"))
})
