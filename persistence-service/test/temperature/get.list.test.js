const db = require('../util/db')
const latestTests = require('../util/templates/pairTimestampValue/list')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const registerRoute = "/temperature/register"
const latestRoute = "/temperature/list"

test("Retreiving correct Temperature list", async () => {
    await latestTests.correctList(registerRoute, latestRoute)
})

test("Not existing Settings id for Temperature list", async () => {
    await latestTests.notExistingId(latestRoute)
})

test("Wrong token for Temperature list", async () => {
    await latestTests.wrongToken(latestRoute)
})
