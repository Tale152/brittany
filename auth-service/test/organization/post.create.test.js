const server = require('../../src/server')
const httpTest = require('../util/httpTest')
const db = require('../util/db')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const organizationName = "TestOrganization"
const name = "Peter"
const surname = "Parker"
const mail = "peter.parker@test.com"
const birthdate = "1997-12-31"
const password = "psw"
const correctBody = {
    organizationName: organizationName,
    name: name,
    surname: surname,
    mail: mail,
    birthdate: birthdate,
    password: password
}

async function organizationCreate(body, code, then){
    await httpTest.post(server, "/organization/create", body, "", code, then)
}

test("Correct Organization creation", async () => {
    await organizationCreate(correctBody, 201, (res) => expect(res.body).toHaveProperty("token"))
})

test("Block Organization creation on duplicate Organization name", async () => {
    await organizationCreate(correctBody, 201, (res) => expect(res.body).toHaveProperty("token"))
    await organizationCreate(
        {
            organizationName: organizationName,
            name: name,
            surname: surname,
            mail: "different." + mail,
            birthdate: birthdate,
            password: password
        },
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})

test("Block Organization creation on duplicate Farmer mail", async () => {
    await organizationCreate(correctBody, 201, (res) => expect(res.body).toHaveProperty("token"))
    await organizationCreate(
        {
            organizationName: "different " + organizationName,
            name: name,
            surname: surname,
            mail: mail,
            birthdate: birthdate,
            password: password
        },
        406,
        (res) => expect(res.body).toHaveProperty("err")
    )
})
