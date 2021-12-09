const server = require('../src/server')
const supertest = require('supertest')
const db = require('./util/db')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

test("Checking for a temperature existence with NaN value", async () =>{
  await supertest(server)
    .get("/temperature/exists")
    .query({value: "wrong"})
    .set('Accept', 'application/json')
    .expect(406)
})

test("Checking for a temperature existence without specifying a value", async () => {
    await supertest(server)
      .get("/temperature/exists")
      .set('Accept', 'application/json')
      .expect('Content-Type', /json/)
      .expect(406)
  }
)

test("Checking for a temperature existence of a just written temperature", async () => {
  await supertest(server)
    .post("/temperature/save")
    .send({time: "", value: 420})
    .set('Accept', 'application/json')
    .expect('Content-Type', /json/)
    .expect(200)

  await supertest(server)
    .get("/temperature/exists")
    .query({value: 420})
    .set('Accept', 'application/json')
    .expect('Content-Type', /json/)
    .expect(200)
    .then((response) => expect(response.body.exists).toBe(true))
  }
)

test("Checking for a temperature existence on non-existing temperature", async () => {
  await supertest(server)
    .get("/temperature/exists")
    .query({value: 420})
    .set('Accept', 'application/json')
    .expect('Content-Type', /json/)
    .expect(200)
    .then((response) => expect(response.body.exists).toBe(false))
  }
)
  