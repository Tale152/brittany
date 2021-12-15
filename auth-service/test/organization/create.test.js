const supertest = require('supertest')

const server = require('../../src/server')
const db = require('../util/db')
const rolesSetup = require('../../src/setup/populateRoles')

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
    await supertest(server)
        .post("/organization/create")
        .send(body)
        .set('Accept', 'application/json')
        .expect('Content-Type', /json/)
        .expect(code)
        .then((res) => then(res))
}

test("Correct Organization creation", async () => {
    await rolesSetup.populateRoles()
    await organizationCreate(correctBody, 201, (res) => expect(res.body).toHaveProperty("token"))
})

test("Block Organization creation on duplicate Organization name", async () => {
    await rolesSetup.populateRoles()
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
    await rolesSetup.populateRoles()
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
