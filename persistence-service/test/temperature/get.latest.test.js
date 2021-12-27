const db = require('../util/db')
const latestTests = require('../util/templates/pairTimestampValue/latest')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const registerRoute = "/temperature/register"
const latestRoute = "/temperature/latest"

test("Retreiving with just one value for Temperature", async () => {
    await latestTests.latestOneValue(registerRoute, latestRoute)
})

test("Retreiving with multiple values for Temperature", async () => {
    await latestTests.latestMultipleValues(registerRoute, latestRoute)
})

test("Wrong token for Temperature", async () => {
    await latestTests.wrongToken(latestRoute)
})
