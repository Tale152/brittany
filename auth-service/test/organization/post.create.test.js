const server = require('../../src/server')
const httpTest = require('../util/httpTest')
const db = require('../util/db')
const values = require('../util/values')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

async function organizationCreate(body, code, then){
    await httpTest.post(server, "/organization/create", body, "", code, then)
}

test("Correct Organization creation", async () => {
    await organizationCreate(values.correctOrganizationBody, 201, (res) => expect(res.body).toHaveProperty("token"))
})

test("Block Organization creation on duplicate Organization name", async () => {
    await organizationCreate(values.correctOrganizationBody, 201, (res) => expect(res.body).toHaveProperty("token"))
    await organizationCreate(
        {
            organizationName: values.organizationName,
            name: values.name,
            surname: values.surname,
            mail: "different." + values.mail,
            birthdate: values.birthdate,
            password: values.password
        },
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})

test("Block Organization creation on duplicate Farmer mail", async () => {
    await organizationCreate(values.correctOrganizationBody, 201, (res) => expect(res.body).toHaveProperty("token"))
    await organizationCreate(
        {
            organizationName: "different " + values.organizationName,
            name: values.name,
            surname: values.surname,
            mail: values.mail,
            birthdate: values.birthdate,
            password: values.password
        },
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})
