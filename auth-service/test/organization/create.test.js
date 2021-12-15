const supertest = require('supertest')

const server = require('../../src/server')
const db = require('../util/db')
const rolesSetup = require('../../src/setup/populateRoles')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

test("Checking for Organization creation", async () => {
    await rolesSetup.populateRoles()
    await supertest(server)
        .post("/organization/create")
        .send({
            organizationName: "TestOrganization",
            name: "Peter",
            surname: "Parker",
            mail: "peter.parker@test.com",
            birthdate: "1997-12-31",
            password: "psw"
        })
        .set('Accept', 'application/json')
        .expect('Content-Type', /json/)
        .expect(201)
        .then((res) => expect(res.body).toHaveProperty("token"))
    }
)
