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

async function correctOrganizationCreation(){
    await rolesSetup.populateRoles()
    await supertest(server)
        .post("/organization/create")
        .send(correctBody)
        .set('Accept', 'application/json')
        .expect('Content-Type', /json/)
        .expect(201)
        .then((res) => expect(res.body).toHaveProperty("token"))
}

test("Correct Organization creation", correctOrganizationCreation)

test("Block Organization creation on duplicate Organization name", async () => {
    await correctOrganizationCreation()
    await supertest(server)
        .post("/organization/create")
        .send({
            organizationName: organizationName,
            name: name,
            surname: surname,
            mail: "different." + mail,
            birthdate: birthdate,
            password: password
        })
        .set('Accept', 'application/json')
        .expect('Content-Type', /json/)
        .expect(406)
})
