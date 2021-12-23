const db = require('../util/db')
const latestTests = require('../util/templates/pairTimestampValue/latest')

beforeAll((done) => db.createConnectionToTestDB(done))
beforeEach(() => db.resetTestDB())
afterAll((done) => db.dropConnectedTestDB(done))

const registerRoute = "/airHumidity/register"
const latestRoute = "/airHumidity/latest"

test("Retreiving with just one value for Air Humidity", async () => {
    await latestTests.latestOneValue(registerRoute, latestRoute)
})

test("Retreiving with multiple values for for Air Humidity", async () => {
    await latestTests.latestMultipleValues(registerRoute, latestRoute)
})

test("Not existing Settings id for for Air Humidity", async () => {
    await latestTests.notExistingId(latestRoute)
})

test("Wrong token for for Air Humidity", async () => {
    await latestTests.wrongToken(latestRoute)
})
